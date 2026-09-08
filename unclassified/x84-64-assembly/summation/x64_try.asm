%include "io64.inc"

; Summation program from 1 to 10
; Intro to x84-64 assembly programming

section .text
global main
main:
    ;write your code here
    mov rcx, 10     ; rcx <-- 10; mov dst, src, loop=10
    mov rax, 0      ; rax <-- 0; rax is the ans
L1:    
    add rax, rcx    ; rax = rax + rcx; add dst, src
    dec rcx         ; rcx--
    jnz L1
    
    PRINT_DEC 8, rax  ; I/O macro and not assembly language, part of SASM (8 - data size in bytes)
    xor rax, rax      ; reset rax to 0 before exiting
    ret