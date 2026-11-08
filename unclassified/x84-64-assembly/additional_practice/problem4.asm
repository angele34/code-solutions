%include "io64.inc"

section .data
    var1 times 200 db 0         ; reserve up to 200 characters for input
    OUTPUT times 200 db 0       ; reserve up to 200 characters for output
    
section .text
global main
main:
    PRINT_STRING "var db '"
    GET_STRING var1, 200        ; read input into var1 with max of 200 chars
    
    PRINT_STRING var1
    PRINT_STRING ".',0"
    NEWLINE
    
    xor rsi, rsi                ; rsi = input index
    xor rdi, rdi                ; rdi = output index
    MOV bl, 1                   ; bl = flag (1 -> capitalize next char)
check_char:
    MOV al, [var1+rsi*1]        ; get the current char
    cmp al, 0                   ; check for end of string
    JE output
    
    ; convert the rest of the chars to uppercase if it is the first word after a space
    cmp al, 32
    JE is_whitespace
    
    cmp bl, 1
    JNE store_char
    
    cmp al, 'a'
    JL store_char               ; if less than 'a', not lowercase
    cmp al, 'z'                 
    JG store_char               ; if greater than 'z' not lowercase

    ; convert to uppercase
    SUB al, 32
    
    ; turn off flag so next chars arent capitalized
    MOV bl, 0
    JMP store_char
    
is_whitespace:
    MOV bl, 1
    JMP store_char
    
store_char:
    MOV [OUTPUT+rdi], al        ; just copy current char to output
    inc rsi                     ; move to next input char
    inc rdi                     ; move to next output char
    JMP check_char              ; loop till EOS

output:
    NEWLINE
    PRINT_STRING "Screen Output: "
    PRINT_STRING OUTPUT
    
    xor rax, rax
    ret