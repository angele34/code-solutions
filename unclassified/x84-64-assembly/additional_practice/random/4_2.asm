%include "io64.inc"

; 4.2 Maximum and Minimum
section .data
    ARR db -5, -3, 12, 7, -9, 0, 21, -1
section .text
global main

main:
    MOV al, ARR[0]          ; al=max
    MOV bl, ARR[1]          ; bl=min (set a large number)
    
    MOV rcx, 8
    xor r8, r8              ; r8=index
    LEA rsi, [ARR]          ; load memory of ARR to rsi

L1:
    MOV dl, [r8+rsi*1]
    ; check for maximum
    CMP dl, al
    JG max
    
    CMP dl, bl
    JL min
    
    inc r8
    LOOP L1
done:
    PRINT_STRING "MAX: "
    PRINT_DEC 1, al
    NEWLINE
    PRINT_STRING "MIN: "
    PRINT_DEC 1, bl
    xor rax, rax
    ret
max:
    MOV al, dl
    JMP L1
min:
    MOV bl, dl
    JMP L1
    
    
    