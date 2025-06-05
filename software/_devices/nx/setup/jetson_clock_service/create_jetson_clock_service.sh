#!/bin/bash

echo "copy service file to /etc/systemd/system ..."
sudo cp ./jetsonClocks.service /etc/systemd/system/
echo "Done"
echo "start change mode ..."
sudo chmod 644 /etc/systemd/system/jetsonClocks.service
echo "Done"
echo "start reload service and enable the service ..."
sudo systemctl daemon-reload
sudo systemctl enable jetsonClocks.service
echo "Done"
echo "start the service"
sudo systemctl start jetsonClocks.service
echo "finish, please check the fan is spinning! "
