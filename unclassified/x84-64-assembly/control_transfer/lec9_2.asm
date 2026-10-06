; write a program that gets the sum of the elements in the list, "LIST".
; let each element in "LIST" be represented as a word.
; assume that the number of elements in "LIST" is in "COUNT"

%include "io64.inc"
section .data
    LIST dw 1, 2, 3, 4, 5
    COUNT dq 5
section .text
global main
main:
    xor rax, rax        ; initialize rax=0; let rax for cumulative sum
    xor rbx, rbx        ; initialize rbx=0; let rbx be the index (i)
    mov rcx, [COUNT]
L1:
    ; 2 because each element in dw is 2 bytes (16 bits)
    add ax, [LIST+rbx*2]; ax = ax + LIST[i] (ith element of list)
    inc rbx             ; i++
    loop L1
    
    PRINT_STRING "The sum is: "
    PRINT_DEC 2, ax
    
    xor rax, rax
    ret