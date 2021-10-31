cd ..
cd banks
cd bank14

:: Setup.
bmp2tile.exe raw/splash.bmp    -savetiles "splash (tiles).psgcompr"    -removedupes -nomirror -planar -tileoffset 112 -savetilemap "splash (tilemap).stmcompr"   -savepalette "splash (palette).bin"   -fullpalette -exit
bmp2tile.exe raw/simpsons.bmp  -savetiles "simpsons (tiles).psgcompr"  -removedupes -nomirror -planar -tileoffset 96  -savetilemap "simpsons (tilemap).stmcompr" -savepalette "simpsons (palette).bin" -fullpalette -exit


:: Convert.
cd ..
folder2c bank14 bank14 14


:: Compile
sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK14 bank14.c

:: Cleanup
if exist "*.asm" del "*.asm" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.sym" del "*.sym" > nul

cd ..
cd scripts