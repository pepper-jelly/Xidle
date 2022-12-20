### Help
```
Xidle: [time] [command(s)]
    Execute command(s) after n minutes of inactivity.
    Examples:
    Xidle 5 "xset dpms force off; i3lock --nofork" &
    Xidle 1 "xdg-screensaver reset" &
```

### Build and dependencies
```
gcc Xidle.c -lX11 -lXss -o Xidle

libxss
libx11
libxext
libxcb
libxau
libxdmcp
```

### Note
Command(s) will be executed only once after timer triggered(then it resets after activity).
