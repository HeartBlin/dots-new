#!/bin/sh

printf "Select a option:\n"
printf "  [1] Shutdown\n"
printf "  [2] Reboot\n"
printf "  [3] Log Out\n"
printf "  [*] Exit\n"
while true; do
    read -p "> " cond
    case $cond in
        1 ) printf "Shutting down...\n"; systemctl poweroff; break;;
        2 ) printf "Rebooting..."; systemctl reboot; break;;
        3 ) printf "Logging out..."; hyprctl dispatch exit; break;;
        * ) printf "Quitting..."; break;;
    esac
done