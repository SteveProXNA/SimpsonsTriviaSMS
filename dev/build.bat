@echo off


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





del *.asm > nul
del *.ihx > nul
del *.lk > nul
del *.lst > nul
del *.map > nul
del *.noi > nul
REM del *.rel > nul
del main.rel > nul
del *.sym > nul

output.sms