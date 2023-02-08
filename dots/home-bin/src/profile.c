#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
    char status[12];
    FILE *getstatus = popen("asusctl profile -p | cut -c 19-", "r");
    while (fgets(status, 12, getstatus) != NULL)
    printf("%i", strlen(status));
    if (strlen(status) == 6) {
        system("asusctl profile -P Balanced");
        system("notify-send -u low -t 1500 \"Active profile is Balanced\"");
    }
    else if (strlen(status) == 9) {
        system("asusctl profile -P Performance");
        system("notify-send -u low -t 1500 \"Active profile is Performance\"");
    }
    else {
        system("asusctl profile -P Quiet");
        system("notify-send -u low -t 1500 \"Active profile is Quiet\"");
    }
    pclose(getstatus);
}