%include "io64.inc"
section .data
    A dq 0x1111_2222_3333_4444
    B dq 0x5555_6666_7777_8888
section .text
global main
main:
    PRINT_STRING "Before swap: "
    NEWLINE
    PRINT_STRING "A: "
    PRINT_HEX 8, [A]
    NEWLINE
    PRINT_STRING "B: "
    PRINT_HEX 8, [B]
    NEWLINE
    
    ; move value of A into temp register
    MOV rsi, [A]
    ; move value of B into temp register    
    MOV r8, [B]
    ; swap
    MOV [B], rsi
    MOV [A], r8
    
    NEWLINE
    PRINT_STRING "After Swap: "
    NEWLINE
    PRINT_STRING "A: "
    PRINT_HEX 8, [A]
    NEWLINE
    PRINT_STRING "B: "
    PRINT_HEX 8, [B]
    NEWLINE
    
    xor rax, rax
    ret