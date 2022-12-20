#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <X11/extensions/scrnsaver.h>

int main(int argc, char *argv[]) {
    Display *display = XOpenDisplay(0);
    if (display == NULL) return 1;

    if (argc <= 2) {
        printf("%1$s: [time] [command(s)]\n"
               "    Execute command(s) after n minutes of inactivity.\n\n"
               "    Examples:\n"
               "    %1$s 5 \"xset dpms force off; i3lock --nofork\" &\n"
               "    %1$s 1 \"xdg-screensaver reset\" &\n", argv[0]);
        return 1;
    }

    XScreenSaverInfo *info = XScreenSaverAllocInfo();
    int a = atoi(argv[1]);
    char *b = argv[2];
    int c = 0;
    int m;

    if (argc == 3) while(1)
    {
        XScreenSaverQueryInfo(display, DefaultRootWindow(display), info);
        m = info->idle/60000;
        if (m < a && c == 0) c = 1;
        if (m >= a && c == 1) {
            c = 0;
            system(b);
        }
        sleep(15);
    }
    return 0;
}
