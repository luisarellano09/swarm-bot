#################################################################
#                                                               #
#   config.sh                                                   #
#                                                               #
#   This script install all the dependencies of the system      #
#                                                               #
#   sh config.sh                                                #
#                                                               #
#################################################################

# Previous Steps
#   sudo raspi-config
#       System Options
#           User: pi
#           Hostname: omnipi
#           Boot/Auto Login: B2 Console Autologin
#       Interface Options
#           Camera: disable
#           SSH: enable
#           VNC: disable
#           SPI: disable
#           I2C: disable
#           Serial Port: No Shell / enable
#           Wire: disable
#           Remote GPIO: disable
#
#   copy the config.sh in the root and execute.
#

# In Host
# ssh-copy-id pi@omnipi.local


clear

echo "This script install all the dependencies of the system"

echo "****** Updating ******"
sudo apt update -y && sudo apt upgrade -y && sudo apt dist-upgrade -y


echo "****** Creating Folders ******"
mkdir omni && cd omni && mkdir data


echo "****** Set Timezone ******"
sudo timedatectl set-timezone Europe/Berlin
sudo timedatectl set-ntp true


echo "****** Installing Applications ******"
sudo apt install htop -y && sudo apt install nano -y && sudo apt install screen -y


echo "****** Installing Serial lib ******"
sudo apt install libudev-dev -y


echo "****** Setup Docker ******"
sudo apt-get update
sudo apt-get install ca-certificates curl
sudo install -m 0755 -d /etc/apt/keyrings
sudo curl -fsSL https://download.docker.com/linux/debian/gpg -o /etc/apt/keyrings/docker.asc
sudo chmod a+r /etc/apt/keyrings/docker.asc
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/debian \
  $(. /etc/os-release && echo "$VERSION_CODENAME") stable" | \
  sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
sudo apt-get update
sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin -y
sudo groupadd docker
sudo usermod -aG docker $USER
sudo systemctl enable docker.service
sudo systemctl enable containerd.service


echo "****** Create SSL Certificates ******"
cd /home/pi/omni/data && mkdir certs && cd certs
sudo openssl req -newkey rsa:4096 -nodes -keyout domain.key -x509 -days 800 -out domain.crt
sudo chmod a+rw domain.key
sudo chmod a+rw domain.crt


echo "****** Set eth0 IP ******"
sudo nmcli con mod "Wired connection 1" ipv4.method manual ipv4.addr 172.168.10.10/24 ipv4.route-metric 20100


echo "****** Docker Swarm ******"
docker swarm init --advertise-addr 172.168.10.10
# see status: docker node ls
# After adding the swarm in omninx
docker node promote omninx


echo "****** Disable GUI ******"
sudo systemctl set-default multi-user.target
#sudo systemctl set-default graphical.target    # Enable

