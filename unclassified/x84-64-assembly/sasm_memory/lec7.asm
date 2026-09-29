%include "io64.inc"

section .data
    var1 db 0
    var2 dw 0
    var3 dd 0
    var4 dq 0
    
section .text
global main
main:
    
    GET_DEC 2, var1
    ; ==== Tracing input ====
    ; input: 2000 (representing in 2 bytes)->
    ; 0000 0111 1101 0000 (in binary) -> 
    ; -1024 + 512 + 256 + 128 + 16 = -48 (output)
    
    ; >>>> in hex: 07D0
    ; if stored in memory:
    ; var4 (8 bytes)
    ; var3 (4 bytes)
    ; var2 (2 bytes) 07  <------ oversteps into var2
    ; var1 (1 byte) D0
    ; ========================

    ; ======
    ; in GET_DEC 1, var1, this still prints -48
    ; Why?
    
    ; GET_DEC 1, var1
    ; Input: 2000
    ;
    ; 2000 = 0000 0111 1101 0000
    ; Only 1 byte is stored:
    ;        1101 0000
    ;
    ; As unsigned:
    ; 1101 0000 = 128 + 64 + 16 = 208
    ;
    ; As signed (two's complement):
    ; 1101 0000
    ; 0010 1111  ; invert
    ; 0011 0000  ; +1 = 48
    ;
    ; Therefore:
    ; PRINT_UDEC 1, var1 -> 208
    ; PRINT_DEC  1, var1 -> -48
    ; ========================

    PRINT_DEC 1, var1   
    NEWLINE
    PRINT_DEC 2, var2
    NEWLINE
    GET_DEC 4, var3
    PRINT_DEC 4, var3
    NEWLINE
    PRINT_DEC 8, var4
    NEWLINE
    xor rax, rax
    ret