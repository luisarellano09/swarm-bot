#!/bin/bash

# Path to the script folder
SCRIPT_PATH="/home/ubuntu/Workspace/swarm-bot/omnibot/sw/edge/deploy/pc/scripts/"

# Check if the script folder exists
if [ -d "$SCRIPT_PATH" ]; then

    # Permissions
    sudo chmod +x $SCRIPT_PATH/omni.sh

    # Check if the script is already added to ~/.profile
    if grep -q "$SCRIPT_PATH" /home/ubuntu/.profile; then
        echo "The script folder is already added to /home/ubuntu/.profile."
    else
        echo "Adding the script folder to /home/ubuntu/.profile."
        echo "export PATH=\$PATH:$SCRIPT_PATH" | sudo tee -a /home/ubuntu/.profile
        source /home/ubuntu/.profile
    fi
else
    echo "Error: The script folder does not exist at $SCRIPT_PATH."
fi
