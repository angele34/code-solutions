%include "io64.inc"

; 4.1 Count null terminated list
section .data
    ALPHA db 0x12, 0x34, 0x56, 0x99, 0x00
    COUNT db 0
section .text
global main
main:    
    xor rsi, rsi        ; let rsi=index
    LEA rax, [ALPHA]
count:
    MOV bl, [rax+rsi*1]
  
    CMP bl, 0
    JE done
    
    ; specify size when incrementing memory variable
    inc byte [COUNT]
    inc rsi
    
    JMP count
done: 
    PRINT_DEC 1, [COUNT]
    
    xor rax, rax
    ret