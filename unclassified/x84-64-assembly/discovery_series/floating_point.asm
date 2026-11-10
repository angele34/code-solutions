; Reyes, Angel Arwen S30D

%include "io64.inc"

section .data
    A dq 2.0
    B dq -5.0
    C dq -3.0
    
    FOUR dq 4.0
    TWO dq 2.0
    NEG_ONE dq -1.0
section .text
global main
main:
    mov rbp, rsp; for correct debugging
    ; compute for b^2
    MOVSD xmm0, [B]   ; preserve value of B
    MULSD xmm0, xmm0 
    
    ; compute 4ac
    MOVSD xmm1, [A]
    MULSD xmm1, [C]
    ; multiply a*c by 4
    MULSD xmm1, [FOUR]
    
    ; get the difference between b^2 - 4ac
    VSUBSD xmm2, xmm0, xmm1
    
    ; get the squareroot of xmm2
    SQRTSD xmm2, xmm2
    
    ; get value for -b
    MOVSD xmm3, [B]
    MULSD xmm3, [NEG_ONE]
    
    ; compute for numerators -b * sqrt and -b * sqrt
    VADDSD xmm4, xmm3, xmm2     ; xmm4 = -b + sqrt(b^2 - 4ac)
    VSUBSD xmm5, xmm3, xmm2     ; xmm5 = -b - sqrt(b^2 - 4ac)
    
    ; Compute denominator
    MOVSD xmm6, [A]
    MULSD xmm6, [TWO]
    
    ; Divide numerator
    VDIVSD xmm4, xmm4, xmm6
    VDIVSD xmm5, xmm5, xmm6
    xor rax, rax
    ret