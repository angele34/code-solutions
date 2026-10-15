; Write a program to compute the perimeter and area of a square.
; The side of the square is obtained from the input prompt.
; Output the required result. There should be an error check
; for negative input. Porgam should support result value up to 2^32

; Perimeter = 4*s, Area = s^2

%include "io64.inc"
section .text
global main
main:
    PRINT_STRING "Enter length: "

    the_beginning: 
        GET_DEC 4, eax     ; reads 64-bit unsigned int
        
        CMP eax, 0          ; compare rax with 0
        JL the_beginning    ; Jump if less than 0
        
        PRINT_DEC 4, eax
        NEWLINE
        
        ; store length in ESI to preserve it
        MOV esi, eax
        
        ; calculate perimeter (4*s)
        MOV ebx, esi      ; let ebx be perimeter
        IMUL ebx, 4       ; ebx = ebx * 4
        
        PRINT_STRING "Perimeter: "
        PRINT_DEC 4, ebx
        NEWLINE
            
        ; calculate area (s^2)
        MOV eax, esi
        IMUL eax, eax
        PRINT_STRING "Area: "
        PRINT_DEC 8, eax
        NEWLINE
        
        xor rax, rax
        ret