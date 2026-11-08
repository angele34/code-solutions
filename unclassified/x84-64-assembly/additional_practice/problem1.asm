%include "io64.inc"

section .text
global main
main:
    PRINT_STRING "Input: "
    GET_DEC 8, rax
    PRINT_DEC 8, rax
    NEWLINE
    
    xor rcx, rcx    ; let rcx be the sum
    MOV rcx, rax
    
    MOV rsi, rax    ; preserve original val of rax
    
    xor rdx, rdx    
    MOV r8d, 2
    IDIV r8d        
    
    cmp rdx, 0      ; check if input is odd/even
    JE is_even
    
    JMP is_odd
    
is_even:
    CMP rsi, 2
    JLE sum  
    
    JMP sum_nums
    
is_odd:
    CMP rsi, 1
    JLE sum  
    
    JMP sum_nums
    
sum_nums:

    MOV rbx, rsi    ; let rbx be the next number in factorial
    SUB rbx, 2
    
    IMUL rcx, rbx   ; multiply the adjacent numbers
    
    MOV rsi, rbx
    
    JMP is_even
    
sum:
    PRINT_STRING "Output: "
    PRINT_DEC 8, rcx

    xor rax, rax
    ret