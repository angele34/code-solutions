%include "io64.inc"
section .data
    TBL dw 0x0A0B, 0x1C1D, 0x2E2F, 0x3031, 0x4243
section .text
global main
main:
    LEA RAX, [TBL]
    ; TBL[0] 0A0B Offset 0
    ; TBL[1] 1C1D Offset 2
    ; TBL[2] 2E2F Offset 4
    ; TBL[3] 3031 Offset 6
    ; TBL[4] 4243 Offset 8
    MOV AX, [RAX+6]
    PRINT_HEX 8, AX
    
    xor rax, rax
    ret