@echo off
REM echo Build gfx.c and gfx.h from gfx folder
folder2c ..\gfx gfx

REM echo Build psg.c and psg.h from psg folder
folder2c ..\psg psg


REM echo Build gfx
sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 gfx.c

REM echo Build psg
sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 psg.c


REM echo Build banks.c and banks.h from banks folder
cd banks	
folder2c bank6 bank6 6
folder2c bank7 bank7 7


REM echo Build banks	
sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK2 bank2.c
sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK3 bank3.c
sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK4 bank4.c
sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK5 bank5.c
sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK6 bank6.c
sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK7 bank7.c
cd ..


REM echo Build main
sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 main.c
if %errorlevel% NEQ 0 goto :EOF

REM echo Linking
sdcc -o output.ihx --Werror --opt-code-speed -mz80 --no-std-crt0 --data-loc 0xC000 ^
-Wl-b_BANK2=0x8000 ^
-Wl-b_BANK3=0x8000 ^
-Wl-b_BANK4=0x8000 ^
-Wl-b_BANK5=0x8000 ^
-Wl-b_BANK6=0x8000 ^
-Wl-b_BANK7=0x8000 ^
..\crt0\crt0_sms.rel ^main.rel ^
..\lib\SMSlib.lib ^
..\lib\PSGlib.rel ^
banks\bank2.rel ^
banks\bank3.rel ^
banks\bank4.rel ^
banks\bank5.rel ^
banks\bank6.rel ^
banks\bank7.rel ^
gfx.rel ^
psg.rel

if %errorlevel% NEQ 0 goto :EOF


REM echo Binary output
ihx2sms output.ihx output.sms
if %errorlevel% NEQ 0 goto :EOF


REM echo Copy output
copy output.sms ..\asm
copy output.sms ..\SimpsonsTriviaSMS.sms


REM echo Disassemble output
cd ..\asm
smsexamine.exe output.sms
cd ..\dev


REM echo Delete
cd banks
del *.asm > nul
del *.lst > nul
del *.rel > nul
del *.sym > nul
cd ..

del *.asm > nul
del *.ihx > nul
del *.lk > nul
del *.lst > nul
del *.map > nul
del *.noi > nul
del *.rel > nul
del *.sym > nul

output.sms