gcc -c ./kernel/main.c -o main.o
gcc -c ./kernel/x86/ld32.c -o ld32.o
gcc -c ./ioctl/terminal.c -o terminal.o
gcc main.o ld32.o terminal.o -o ld
