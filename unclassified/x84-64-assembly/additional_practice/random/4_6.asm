%include "io64.inc"

; 4.6 Reverse in place
section .data
    ARR dd 1, 2, 3, 4, 5, 6, 7       ;(32 bit)
section .text
global main
main:
    PRINT_STRING "Before:"
    LEA rsi, [ARR]
    
    MOV ecx, 7
    xor r8, r8                      ; r8=index
        
display_before:
    PRINT_STRING " "
    MOV eax, [rsi+r8*4]
    PRINT_DEC 4, eax
    
    INC r8d
    DEC ecx
    JNZ display_before
    
    ; reset for display after
    xor r8, r8  ; left idx=0
    MOV r9, 6   ; right idx=6
reverse:
    CMP r8, r9
    JGE reverse_done
    
    MOV eax, [rsi+r8*4] ; get left value
    MOV ebx, [rsi+r9*4] ; get right value
    ; swap
    MOV [rsi+r8*4], ebx ; store right value on left
    MOV [rsi+r9*4], eax ; store left value on right
    
    DEC r9
    INC r8
    
    JMP reverse
    
reverse_done:
    NEWLINE
    PRINT_STRING "After:"
    xor r8, r8
    mov ecx, 7
display_after:
    PRINT_STRING " "
    mov eax, [rsi+r8*4]
    PRINT_DEC 4, eax
    INC r8
    DEC ecx
    JNZ display_after
done:
    xor rax, rax
    ret