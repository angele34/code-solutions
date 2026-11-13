%include "io64.inc"
; 6.4: character frequency
section .data
    TEXT db "mississippi", 0
section .text
global main
main:
    mov rbp, rsp; for correct debugging
    PRINT_STRING "Enter character: "
    GET_CHAR al
    PRINT_CHAR al
    NEWLINE
    
    LEA rsi, [TEXT]
    xor rcx, rcx
    
    xor rdi, rdi        ; counter
    JMP count
    
equal:
    inc rdi
    JMP count
    
count:
    MOV bl, [rsi+rcx*1]
    
    cmp bl, 0   ; check if have reached end of string
    JE print
    
    inc rsi
    
    cmp al, bl
    JE equal
    
    JMP count
    
print:
    PRINT_STRING "Count: "
    PRINT_DEC 8, rdi
    
    xor rax, rax
    ret