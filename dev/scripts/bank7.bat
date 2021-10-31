cd ..
cd banks
cd bank7

:: Setup.
bmp2tile.exe raw/actor04.bmp -savetiles "actor04 (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "actor04 (tilemap).stmcompr" -savepalette "actor04 (palette).bin" -fullpalette -exit
bmp2tile.exe raw/actor05.bmp -savetiles "actor05 (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "actor05 (tilemap).stmcompr" -savepalette "actor05 (palette).bin" -fullpalette -exit
bmp2tile.exe raw/actor06.bmp -savetiles "actor06 (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "actor06 (tilemap).stmcompr" -savepalette "actor06 (palette).bin" -fullpalette -exit
bmp2tile.exe raw/actor07.bmp -savetiles "actor07 (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "actor07 (tilemap).stmcompr" -savepalette "actor07 (palette).bin" -fullpalette -exit

:: Convert.
cd ..
folder2c bank7 bank7 7

:: Compile
sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK7 bank7.c

:: Cleanup
if exist "*.asm" del "*.asm" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.sym" del "*.sym" > nul

cd ..
cd scripts