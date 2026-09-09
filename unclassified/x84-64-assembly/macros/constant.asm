; SASM Assembler has its macros and pseudo-instructions that are NOT part of the x86-64 assembly language.
%include "io64.inc"
section .text
global main
main:
    PRINT_DEC 8, -100000
    NEWLINE
    PRINT_UDEC 1,255
    NEWLINE
    PRINT_UDEC 2,65535
    NEWLINE
    PRINT_HEX 4, 0xCAFEBAD1
    NEWLINE
    PRINT_STRING "Hello World"
    NEWLINE
    PRINT_CHAR "A"
    NEWLINE
    
    xor rax, rax    ;
    ret             ; return 0