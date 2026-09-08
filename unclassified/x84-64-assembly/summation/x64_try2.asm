%include "io64.inc"

; program that adds two variables
section .data
i dq 2000
j dq 3000
k dq 0
section .text
global main
main:
    mov rax, [i]        ; k = i+j
    mov rbx, [j]
    add rax, rbx
    mov [k], rax
    PRINT_DEC 8, rax
        
    xor rax, rax        ; reset rax to 0 before exiting
    ret