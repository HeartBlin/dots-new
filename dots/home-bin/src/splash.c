#include <stdio.h>

void main() {
    char splash[100];
    FILE *getsplash = popen("hyprctl splash", "r");
    while (fgets(splash, 100, getsplash) != NULL)
    printf("%s", splash);
    pclose(getsplash);
}