echo start
:: Setup.
cd ../banks/bank11/raw
pcmenc -rto 1 -dt1 12 -dt2 12 -dt3 423 wrong02.wav
mv wrong02.wav.pcmenc ../

:: Convert.
cd ../..
folder2c bank11 bank11 11

:: Compile
sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK11 bank11.c

:: Cleanup
if exist "*.asm" del "*.asm" > nul; 
if exist "*.lst" del "*.lst" > nul; 
if exist "*.sym" del "*.sym" > nul

cd ../scripts
echo -end-