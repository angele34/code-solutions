; Angel Arwen E. Reyes S30D
%include "io64.inc"

section .data
    STRVAR db "ACTGACGTCCCTTT", 0
    OUTPUT times 30 db 0
    DNALEN db 0
section .text
global main
main:
    PRINT_STRING "Original string: "
    PRINT_STRING STRVAR
    NEWLINE  
    
the_beginning:
    mov al, [STRVAR+rsi*1]  ; because db is 1 byte (strvar is unmodified)

    ; copy current char to output
    mov [OUTPUT+rsi*1], al
    cmp al, "T"             ; check if current char is T
    JE replace              ; jump if equal
    inc rsi                 ; for counting length of DNA string and accessing idx
    inc byte [DNALEN]

    cmp al, 0               ; check if have reached the end of the string
    JE the_end

    jmp the_beginning       ; else go to the next char

replace:
    mov al, "U"                 ; replace occurence of T with U
    mov [OUTPUT+rsi*1], al      ; store in mem loc OUTPUT
    inc rsi
    inc byte [DNALEN]
    jmp the_beginning
    
the_end:                        ; exit program
    PRINT_STRING "Modified string: "
    PRINT_STRING OUTPUT
    NEWLINE
    
    PRINT_STRING "Size: "
    PRINT_DEC 1, DNALEN
    
    xor rax, rax
    ret