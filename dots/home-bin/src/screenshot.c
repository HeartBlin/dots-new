#include <stdlib.h>

int main() {
    if (system("grim -g \"$(slurp)\" \"$HOME/Pictures/Screenshots/$(date '+%%y%%m%%d_%%H-%%M-%%S').png\"")) {
        return 1;
    }
    system("notify-send -u low -t 2000 \"Screenshot saved in ~/Pictures/Screenshots/\"");
    return 0;
}