@echo off
REM echo Execute bmp2tile

cd ..\gfx
bmp2tile.exe raw\font.bmp -savetiles "font (tiles).psgcompr" -removedupes -tileoffset 0 -savetilemap "font (tilemap).bin" -savepalette "font (palette).bin" -exit
bmp2tile.exe raw\right.bmp -savetiles "right (tiles).psgcompr" -noremovedupes -nomirror -planar -savepalette "right (palette).bin" -spritepalette -exit
bmp2tile.exe raw\select.png -savetiles "select (tiles).psgcompr" -noremovedupes -nomirror -planar -savepalette "select (palette).bin" -spritepalette -exit
bmp2tile.exe raw\wrong.bmp -savetiles "wrong (tiles).psgcompr" -noremovedupes -nomirror -planar -savepalette "wrong (palette).bin" -spritepalette -exit


cd ..\dev\banks\bank6
bmp2tile.exe raw\splash.bmp -savetiles "splash (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 112 -savetilemap "splash (tilemap).stmcompr" -savepalette "splash (palette).bin" -exit
bmp2tile.exe raw\simpsons.bmp -savetiles "simpsons (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 96 -savetilemap "simpsons (tilemap).stmcompr" -savepalette "simpsons (palette).bin" -exit


cd ..\bank7
bmp2tile.exe raw\maggie.bmp -savetiles "maggie (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 112 -savetilemap "maggie (tilemap).stmcompr" -savepalette "maggie (palette).bin" -exit


cd ..\..