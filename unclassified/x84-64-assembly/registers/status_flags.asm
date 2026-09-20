%include "io64.inc"
section .text
global main
main:
    ; rflags - register, but view it as 1-bit flag
    ; status flags - there are 6
    ; 1. carry flag
    ; 2. zero flag 
    ; 3. sign flag
    ; 4. overflow flag
    ; 5. parity flag
    ; 6. auxiliary or half carry flag
    
    mov al, 0xff
    mov bl, 0xfe
    add al, bl
    
    ;  1111 1111
    ;  1111 1110
    ;  ---------
    ; 1)1111 1101
    
    ; AF=1, CF=1, SF=1, ZF=0, PF=0, OF=0
    
    mov si, 0xffff
    mov di, 0x0001
    add si, di
    
    ;    1111 1111 1111 1111
    ;    0000 0000 0000 0001
    ;    -------------------
    ; 1) 0000 0000 0000 0000
    
    ; AF=1, CF=1, SF=0, ZF=1, PF=0, OF=0
    ; Overflow=0 because 
    
    mov al, 0x25
    mov bl, 0x25
    sub al, bl
    jnz L1
    PRINT_STRING "ZF is 1"
    NEWLINE
    JMP NEXT
L1: PRINT_STRING "ZF is 0"
    NEWLINE

NEXT:
    mov al, 10
    cmp al, 0
    js nega
    PRINT_STRING "It is positive"
    jmp next1
    
nega: PRINT_STRING "It is negative"
next1:
    
    xor rax, rax
    ret