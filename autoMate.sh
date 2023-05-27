#!/bin/bash
SCRIPT_NAME="netAdpt" # change it to however u named ur ELF
SCRIPT_DIR="$HOME/scripts" #this is the folder u built 

mkdir -p "$SCRIPT_DIR" #create that folder 

mv "$SCRIPT_NAME" "$SCRIPT_DIR/" #move the script to that folder
chmod +x "$SCRIPT_DIR/$SCRIPT_NAME" #make it executable if it's not already lad

if [[ ":$PATH:" == *":$SCRIPT_DIR:"* ]]; then
    echo "The script directory is already in the PATH." # this is to check if the scrip is already in path which most likely it ain't but just a measure
else
    echo "export PATH=\$PATH:$SCRIPT_DIR" >> ~/.bashrc # adds it to path 
    echo "Added $SCRIPT_DIR to the PATH in ~/.bashrc." 
fi

source ~/.bashrc # Reload the shell configuration
