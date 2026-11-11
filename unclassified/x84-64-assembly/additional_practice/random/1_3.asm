%include "io64.inc"

section .data
    SRC db "assembly", 0
    DST times 9 db 0
section .text
global main
main:
    LEA rsi, [SRC]
    LEA rdi, [DST]
cpy:
    MOV al, [rsi]
    MOV [rdi], al
    
    INC rsi
    INC rdi
    
    CMP al, 0
    JNE cpy
    
    PRINT_STRING DST
    
    xor rax, rax
    ret