%include "io64.inc"

; 4.5: Linear search
section .data
    ARR dd 14, 7, 92, 3, 55 ; (32 bit)
section .text
global main
main:
    ; read key
    PRINT_STRING "Enter key: "
    GET_DEC 4, eax
    PRINT_DEC 4, ebx
    
    xor rsi, rsi
    xor rcx, rcx    ; idx
    jmp search

    
search:
    ; if have reached this point, not found
    cmp rcx, 5
    JGE invalid
    
    mov ebx, [ARR+rsi*4]
    cmp eax, ebx
    JE done
    
    inc rsi
    inc rcx
    
    jmp search
        
done:
    NEWLINE
    PRINT_STRING "Found at index "
    PRINT_DEC 4, rcx
    
    xor rax, rax
    ret
    
invalid:
    NEWLINE
    PRINT_STRING "Not found"
    xor rax, rax
    ret