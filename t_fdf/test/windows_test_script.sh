# https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

# Install Xming, just keep clicking next, the defaults will do. After installing, you will see a little Xming icon in your icon tray. Now exit xming, and open XLaunch, proceed with the following steps:

#    Click Multiple windows and go to the next page
#    Click Start no client and go to the next page
#    Make sure that the No Access Control box is ticked and go to the next page
#    Click Save configuration and then Finish

# In WSL execute the following command, this will set your display environment variable accordingly (feel free to create an alias :D):

export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0



# compile file
cc -I /usr/include/ minilib_main.c -L ../lib/minilibx_linux/ -lmlx -lXext -lX11 -lm -lbsd

./a.out