cd ..
cd banks

:: Compile
sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK3 bank3.c

:: Cleanup
if exist "*.asm" del "*.asm" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.sym" del "*.sym" > nul

cd ..
cd scripts