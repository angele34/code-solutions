; Write a program that asks the user for two numbers.
; Make the program get the sum of the two numbers,
; Save it into memory location SUM
; Also, make the program print the sum.

%include "io64.inc"

section .data
    prompt1 db "Please enter the first number: ", 0
    prompt2 db "Please enter the second number: ", 0
    ; 0 is the null terminating char
    prompt3 db "The sum of the two numbers is: ", 0
    SUM dq 0
    
section .text
global main
main:
    
    PRINT_STRING prompt1
    GET_DEC 8, rax          ; rax <- 1st number
    PRINT_DEC 8, rax
    NEWLINE
    
    PRINT_STRING prompt2    
    GET_DEC 8, rbx          ; rbx <- 2nd number
    PRINT_DEC 8, rbx
    NEWLINE
    
    add rax, rbx            ; rax = rax + rbx (SUM)
    mov [SUM], rax          ; [SUM[ <- rax
    PRINT_STRING prompt3
    PRINT_DEC 8, [SUM]
    
    xor rax, rax
    ret