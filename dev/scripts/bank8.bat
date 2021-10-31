cd ..
cd banks
cd bank8

:: Setup.
bmp2tile.exe raw/actor08.bmp -savetiles "actor08 (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "actor08 (tilemap).stmcompr" -savepalette "actor08 (palette).bin" -fullpalette -exit
bmp2tile.exe raw/actor09.bmp -savetiles "actor09 (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "actor09 (tilemap).stmcompr" -savepalette "actor09 (palette).bin" -fullpalette -exit
bmp2tile.exe raw/actor10.bmp -savetiles "actor10 (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "actor10 (tilemap).stmcompr" -savepalette "actor10 (palette).bin" -fullpalette -exit
bmp2tile.exe raw/actor11.bmp -savetiles "actor11 (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "actor11 (tilemap).stmcompr" -savepalette "actor11 (palette).bin" -fullpalette -exit

:: Convert.
cd ..
folder2c bank8 bank8 8

:: Compile
sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK8 bank8.c

:: Cleanup
if exist "*.asm" del "*.asm" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.sym" del "*.sym" > nul

cd ..
cd scripts