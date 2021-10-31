echo start
:: Setup.
cd ../banks/bank10/raw
pcmenc -rto 1 -dt1 12 -dt2 12 -dt3 423 right02.wav
pcmenc -rto 1 -dt1 12 -dt2 12 -dt3 423 wrong03.wav
mv right02.wav.pcmenc ../
mv wrong03.wav.pcmenc ../

:: Convert.
cd ../..
folder2c bank10 bank10 10

:: Compile
sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK10 bank10.c

:: Cleanup
if exist "*.asm" del "*.asm" > nul; 
if exist "*.lst" del "*.lst" > nul; 
if exist "*.sym" del "*.sym" > nul

cd ../scripts
echo -end-