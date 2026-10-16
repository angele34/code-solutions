; Write a program to compute the perimeter and area of a square.
; The side of the square is obtained from the input prompt.
; Output the required result. There should be an error check
; for negative input. Porgam should support result value up to 2^32

; Angel Arwen E. Reyes S30D
%include "io64.inc"
section .text
global main
main:
    PRINT_STRING "Enter length: "
    
    GET_DEC 4, eax  ; read up to 2^32
    cmp eax, 0
    JL negative ; jump if negative (less than 0)
    PRINT_DEC 4, eax
    NEWLINE
    
    mov esi, eax    ; store value of eax in esi
    ; Perimeter = 4*s
    IMUL eax, 4
    PRINT_STRING "Perimeter: "
    PRINT_DEC 4, eax
    NEWLINE
    
    ; Area = s*s
    mov ebx, esi
    IMUL ebx, ebx
    PRINT_STRING "Area: "
    PRINT_DEC 4, ebx
    NEWLINE
    xor rax, rax
    ret
negative:
    PRINT_DEC 4, eax
    NEWLINE
    PRINT_STRING "Negative input not allowed, please try again."
    xor rax, rax
    ret

 
    
 