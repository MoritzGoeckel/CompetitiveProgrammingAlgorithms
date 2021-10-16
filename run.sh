#!/bin/sh

# Installation for inotifywait
# sudo apt install inotify-tools

# Other events to listen to
#create,close_write,moved_to,

# Run the first time
clear
racket $1

# Run with every recreation of the file
inotifywait -q -e create -m . |
while read -r directory events filename; do
    if [ "$filename" = $1 ]; then
        clear
        racket $1
    fi
done
