; write a program that determines if a student passes or fails LBYARCH,
; based on their final grade.
; Let the user input the final grade.

%include "io64.inc"
section .text
global main
main:
    
    PRINT_STRING "Please enter your final grade: "
    GET_DEC 8, rax      ; rax <- final grade
    PRINT_DEC 8, rax
    NEWLINE
    
    cmp rax, 100
    jg invalid
    
    ; if rax >= 60 -> pass
    cmp rax, 60
    jge passed      ; jump (>=) then label passed 
    
   ; if not satisfied, skips the passed block
    PRINT_STRING "You failed..."
    jmp FINISH
    ; satisfies condition then goes to passed
passed:
    PRINT_STRING "Congrats! You passed LBYARCH!!"
    jmp FINISH
    
invalid:
    PRINT_STRING "INVALID GRADE ENTERED!!!"
      
FINISH:
    xor rax, rax
    ret