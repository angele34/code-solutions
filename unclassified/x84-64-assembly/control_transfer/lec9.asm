; write a program that determines if a student passes or fails LBYARCH,
; based on their final grade.
; Let the user input the final grade.

%include "io64.inc"
section .data

section .text
global main
main:
    ;write your code here
    
    PRINT_STRING "Please enter your final grade: "
    GET_DEC 8, rax      ; rax <- final grade
    PRINT_DEC 8, rax
    NEWLINE
    
    ; if rax >= 60 -> pass
    cmp rax, 60
    jge passed      ; jump (>=) then label passed 
    
   ; if not satisfied, skips the passed block
    PRINT_STRING "You failed..."
    jmp FINISH
    ; satisfies condition then goes to passed
passed:
    PRINT_STRING "Congrats! You passed LBYARCH!!"
      
FINISH:
    xor rax, rax
    ret