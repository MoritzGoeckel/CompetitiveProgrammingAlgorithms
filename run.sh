# sudo apt install inotify-tools

#create,close_write,moved_to,

clear
inotifywait -e create -m . |
while read -r directory events filename; do
    if [ "$filename" = $1 ]; then
        clear
        racket $1
    fi
done
