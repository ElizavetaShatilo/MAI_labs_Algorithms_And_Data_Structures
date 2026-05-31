g#!/bin/bash

help() {
    echo "Usage: $0 [OPTION]... N DIR"
    echo
    echo "Delete all files in DIR and its subdirectories"
    echo "whose total size in blocks is >= N."
    echo
    echo "One block = 512 bytes (default in GNU coreutils)."
    echo
    echo "Options:"
    echo "  -h, --help     show this help message and exit"
    echo "  -b, --blocks BLOCKS   number of blocks (minimum size)"
    echo "  -d, --directory DIR   target directory"
    echo
    echo "Exit status:"
    echo " 0   if OK,"
    echo " 1   if invalid arguments or missing parameters"
    echo " 2   if DIR does not exist or is not a directory"
    echo " 3   if BLOCKS is not a positive number"
}

if [[ "$1" == "-h" || "$1" == "--help" ]]; then
    help
    exit 0
fi

blocks=""
dir=""

if [[ "$1" == "-b" || "$1" == "--blocks" ]]; then
    blocks="$2"
    if [[ "$3" == "-d" || "$3" == "--directory" ]]; then
        dir="$4"
    else
        help
        exit 1
    fi
elif [[ "$1" == "-d" || "$1" == "--directory" ]]; then
    dir="$2"
    if [[ "$3" == "-b" || "$3" == "--blocks" ]]; then
        blocks="$4"
    else
        help
        exit 1
    fi
else
    help
    exit 1
fi

if ! [[ "$blocks" =~ ^[0-9]+$ ]] || [ "$blocks" -eq 0 ]; then
    echo "Error: blocks must be a positive integer"
    exit 3
fi

if [ ! -d "$dir" ]; then
    echo "Error: directory '$dir' does not exist"
    exit 2
fi

cd "$dir" || exit 2

# 'find' + 'stat' для получения размера в блоках
find . -type f | while read -r file; do
    # 'du -k' было бы в килобайтах, но нам нужны именно блоки.

    if stat --version 2>/dev/null | grep -q "GNU"; then
        blocks_used=$(stat -c "%b" "$file" 2>/dev/null)
    else
        bytes=$(stat -f "%z" "$file" 2>/dev/null)
        blocks_used=$(( (bytes + 511) / 512 ))
    fi

    if [ -z "$blocks_used" ]; then
        continue
    fi

    if [ "$blocks_used" -ge "$blocks" ]; then
        echo "Deleting $file (${blocks_used} blocks)"
        rm -f "$file"
    fi
done
echo "Done."