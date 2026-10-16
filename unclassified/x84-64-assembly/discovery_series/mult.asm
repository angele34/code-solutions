%include "io64.inc"

section .text
global main
main:
    PRINT_STRING "Input A: "
    GET_DEC 4, eax           ; Read 32-bit signed int A into EAX
    PRINT_DEC 4, eax         ; Output A
    NEWLINE
    
    PRINT_STRING "Input B: "
    GET_DEC 4, ebx           ; Read 32-bit signed int B into EBX
    PRINT_DEC 4, ebx         ; Output B
    NEWLINE
    
    ; --- Compute A^4 ---
    ; EAX = A
    IMUL eax, eax            ; EAX = A^2
    IMUL eax, eax            ; EAX = (A^2)^2 = A^4
    
    ; --- Compute B^4 ---
    ; EBX = B
    IMUL ebx, ebx            ; EBX = B^2
    IMUL ebx, ebx            ; EBX = (B^2)^2 = B^4
    
    ; --- Output Results ---
    PRINT_STRING "A^4: "
    PRINT_DEC 4, eax         ; Print A^4
    NEWLINE
    
    PRINT_STRING "B^4: "
    PRINT_DEC 4, ebx         ; Print B^4
    NEWLINE
    
    PRINT_STRING "Y = A^4 + B^4: "
    ADD eax, ebx             ; EAX = A^4 + B^4
    PRINT_DEC 4, eax         ; Print final result
    NEWLINE
    
    xor rax, rax
    ret