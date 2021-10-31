@echo off
REM gfx		Commonly used gfx	not banked

cd ..
cd ..
cd gfx

:: Tiles
bmp2tile.exe raw/font.bmp -savetiles "font (tiles).psgcompr" -noremovedupes -planar -tileoffset 0  -savetilemap "font (tilemap).bin" -savepalette "font (palette).bin" -fullpalette -exit
bmp2tile.exe raw/right.bmp -savetiles "right (tiles).psgcompr" -noremovedupes -nomirror -planar -savepalette "right (palette).bin" -spritepalette -exit
bmp2tile.exe raw/select.png -savetiles "select (tiles).psgcompr" -noremovedupes -nomirror -planar -savepalette "select (palette).bin" -spritepalette -exit
bmp2tile.exe raw/wrong.bmp -savetiles "wrong (tiles).psgcompr" -noremovedupes -nomirror -planar -savepalette "wrong (palette).bin" -spritepalette -exit

cd ../dev

folder2c ../gfx gfx

sdcc --debug -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 gfx.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

::cd ..
cd scripts