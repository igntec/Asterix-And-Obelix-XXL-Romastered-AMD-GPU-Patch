...........................................................................
AMD PATCH FOR 'ASTERIX AND OBELIX XXL ROMASTERED'
...........................................................................

FIXED LIST:

1. Fire
2. Collectables
3. Smoke
4. Fog
5. Gold
6. Rain
7. Hits

Fixes apply only to remastered mode. For example, fire still doesn't work in retro mode.
Also, there are probably more shaders that should be fixed in remastered mode.
First release includes only what is absolutely necessary to enjoy game.

...........................................................................

VERSION INFO (IMPORTANT):

This fix is tested on game version 1.0.33
It might not work with another version of the game.

...........................................................................

INSTALLATION:

Copy content of 'bin' folder to game installation folder. Content of 'bin' folder:
1. opengl32.dll library
2. shaders folder

After some gameplay dummy 'opengl32.dll' will rename itself to 'opengl32.dll.ignore'.
This is by design, to improve game performance.
Don't rename it back (nothing scary happens if you will, it will just rename itself back after some time).

...........................................................................

ADDITIONAL INFO:

This patch can be used on Nvidia, however it will have no effect.

...........................................................................

FOR PROGRAMMERS:

Source code of dummy 'opengl32.dll' is provided in 'src' folder.

...........................................................................
