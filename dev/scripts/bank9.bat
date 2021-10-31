cd ..
cd banks
cd bank9

:: Setup.
bmp2tile.exe raw/actor12.bmp -savetiles "actor12 (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "actor12 (tilemap).stmcompr" -savepalette "actor12 (palette).bin" -fullpalette -exit
bmp2tile.exe raw/actor13.bmp -savetiles "actor13 (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "actor13 (tilemap).stmcompr" -savepalette "actor13 (palette).bin" -fullpalette -exit
bmp2tile.exe raw/actor14.bmp -savetiles "actor14 (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "actor14 (tilemap).stmcompr" -savepalette "actor14 (palette).bin" -fullpalette -exit
bmp2tile.exe raw/actor15.bmp -savetiles "actor15 (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "actor15 (tilemap).stmcompr" -savepalette "actor15 (palette).bin" -fullpalette -exit

:: Convert.
cd ..
folder2c bank9 bank9 9

:: Compile
sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK9 bank9.c

:: Cleanup
if exist "*.asm" del "*.asm" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.sym" del "*.sym" > nul

cd ..
cd scripts