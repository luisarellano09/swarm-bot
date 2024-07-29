#################################################################
#                                                               #
#   config.sh                                                   #
#                                                               #
#   This script install all the dependencies of the system      #
#                                                               #
#   sudo sh config.sh                                           #
#                                                               #
#################################################################

# Previous Steps
#
#   System
#       User: nx
#       Hostname: omninx
#
#       eth0: 172.168.10.11 /24 172.168.10.1
#
#   copy the config.sh in the root and execute.

# In Host
# ssh-copy-id nx@omninx.local


clear


echo "****** Updating ******"
sudo apt update -y && sudo apt upgrade -y && sudo apt dist-upgrade -y


echo "****** Permission no password ******"
sudo usermod -a -G sudo nx
# sudo visudo
# add at the last line
# nx ALL=(ALL) NOPASSWD: ALL


echo "****** Creating Folders ******"
mkdir omni && cd omni && mkdir data
cd ~/omni/data && mkdir face_detector && cd face_detector && mkdir known_faces


echo "****** Set Timezone ******"
sudo timedatectl set-timezone Europe/Berlin
sudo timedatectl set-ntp true


echo "****** Installing Applications ******"
sudo apt install htop -y && sudo apt install nano -y 


echo "****** Installing video******"
sudo apt-get install xorg-dev libglu1-mesa-dev v4l-utils -y


echo "****** Installing Serial lib ******"
sudo apt install libudev-dev -y


echo "****** Installing JTOP ******"
sudo apt install python3-pip -y
sudo pip3 install -U jetson-stats 


echo "****** Setup Docker ******"
sudo apt-get update
sudo apt-get install ca-certificates curl gnupg
sudo install -m 0755 -d /etc/apt/keyrings

curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
echo \
  "deb [arch="$(dpkg --print-architecture)" signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
  "$(. /etc/os-release && echo "$VERSION_CODENAME")" stable" | \
  sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

sudo apt-get update
sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin -y
sudo groupadd docker
sudo usermod -aG docker $USER
sudo systemctl enable docker.service
sudo systemctl enable containerd.service
# sudo nano /etc/docker/daemon.json
# {
#     "runtimes": {
#         "nvidia": {
#             "path": "nvidia-container-runtime",
#             "runtimeArgs": []
#         }
#     },

#     "default-runtime": "nvidia"
# }


echo "****** Installing IntelRealSense ******"
cd
git clone https://github.com/JetsonHacksNano/installLibrealsense.git
cd installLibrealsense
./installLibrealsense.sh 
#realsense-viewer # to start viewer


echo "****** Installing OpenCV with Cuda ******"
cd
git clone https://github.com/mdegans/nano_build_opencv.git
cd nano_build_opencv
./build_opencv.sh 4.10.0


echo "****** Installing Jetpack ******"
sudo apt install nvidia-jetpack -y
sudo apt update
sudo apt dist-upgrade


echo "****** Cleaning ******"
sudo apt remove --purge libreoffice*
sudo apt remove --purge thunderbird*
sudo apt clean
sudo apt autoremove -y


echo "****** Disable GUI ******"
sudo systemctl set-default multi-user.target
#sudo systemctl set-default graphical.target    # Enable


echo "****** Docker Swarm ******"
# see the current token from the sbrpi: docker swarm join-token manager
docker swarm join --token SWMTKN-1-26q18j5orh7nnhob5vevg0lpxhsgbc3erlioct56wafdbqhh0e-2p4xu2npkxp1fierun3yw1xa5 172.168.10.10:2377

# Reboot 
echo "****** Turn off zram ******"
cd /etc/systemd
sudo mv nvzramconfig.sh nvzramconfig.sh.orig


# Reboot
echo "****** Create swap file on NVMe ******"
mkdir nvme
sudo fallocate -l 50G /home/nx/nvme/swapfile
sudo chmod 600 /home/nx/nvme/swapfile
sudo mkswap /home/nx/nvme/swapfile
sudo swapon /home/nx/nvme/swapfile
sudo swapon -s
echo "/home/nx/nvme/swapfile swap swap defaults 0 0" | sudo tee -a /etc/fstab   


echo "****** Install Jetson Inference ******"
cd ~/
git clone --recursive --depth=1 https://github.com/dusty-nv/jetson-inference

# Start the docker container
cd jetson-inference
docker/run.sh

# Inside of the docker container: 
cd tools
./download-models.sh
