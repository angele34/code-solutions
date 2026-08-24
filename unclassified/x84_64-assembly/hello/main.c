// Template C to x86 call

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern void asmhello();

int main(int argc, char *argv[]) {
    asmhello();
    return 0;
}