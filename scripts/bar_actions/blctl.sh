#!/bin/env bash

UPDATE_CMD="$DWM_DIR/scripts/update_bar.sh"

case $1 in
    up)
        light -A 10
        sh -c $UPDATE_CMD
        ;;
    down)
        light -U 10
        sh -c $UPDATE_CMD
        ;;
    *)
        echo "no command $1"
        exit 1
        ;;
esac
