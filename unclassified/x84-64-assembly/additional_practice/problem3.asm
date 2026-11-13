; Angel Arwen E. Reyes S30D
; NOTE: if user enters '-' at beginning of the string,
; the program defaults the error message to negative input.
; I have yet to add additional error checking to direct it to non-numeric input instead.

%include "io64.inc"

section .data
    var1 times 20 db 0
    choice_input times 4 db 0

section .text

global main

main:
    ; Prompt user for input
    xor rsi, rsi
    xor eax, eax

    PRINT_STRING "Input: "
    GET_STRING var1, 20

    ; Check if input is empty
    CMP byte [var1], 0
    JE empty_input

    CMP byte [var1], 0xA
    JE empty_input

    PRINT_STRING var1

    xor rsi, rsi
    xor eax, eax
check_chars:
    mov bl, [var1 + rsi]

    cmp bl, 0
    JE done

    cmp bl, 0xA
    JE done

    ; Check if current char is negative
    cmp bl, '-'
    JE is_neg

    ; Check if current char is not numeric
    cmp bl, '0'
    JL not_numeric

    cmp bl, '9'
    JG not_numeric

    ; Convert ASCII char to numeric value
    sub bl, '0'

    ; EAX = EAX * 10 + digit
    PUSH rdx

    mov edx, 10
    imul eax, edx

    movzx edx, bl
    add eax, edx

    pop rdx
    inc rsi
    jmp check_chars

not_numeric:
    NEWLINE
    PRINT_STRING "Error: non-numeric input"
    JMP choice
is_neg:
    NEWLINE
    PRINT_STRING "Error: negative number input"
    JMP choice
empty_input:
    NEWLINE
    PRINT_STRING "Error: empty input"
    JMP choice
choice:

    NEWLINE
    PRINT_STRING "Do you want to continue (Y/N)?: "

    GET_STRING choice_input, 4

    MOV al, [choice_input]

    CMP al, 'Y'
    JE main

    CMP al, 'y'
    JE main

    CMP al, 'N'
    JE end

    CMP al, 'n'
    JE end

    PRINT_STRING "Invalid choice. Please enter Y or N."
    NEWLINE

    JMP choice

done:
    PRINT_STRING "Sequence: "
    xor r8b, r8b

the_beginning:
    inc r8b
    CMP r8b, 11
    JE choice
    CMP r8b, 1
    JE print_num

    PRINT_STRING ", "
print_num:
    PRINT_DEC 4, eax
    CMP eax, 1
    JE choice
    JMP valid
valid:
    ; Store original value of EAX in EBX
    MOV ebx, eax

    ; 1. Check divisibility by 3
    MOV ecx, 3
    XOR edx, edx

    DIV ecx

    CMP edx, 0
    JE div_by_three

    ; 2. Check if even
    MOV eax, ebx
    MOV ecx, 2
    XOR edx, edx

    DIV ecx

    CMP edx, 0
    JE div_by_two

    ; 3. If odd, multiply by 2 and subtract 1
    MOV eax, ebx
    IMUL eax, 2
    DEC eax

    JMP the_beginning

div_by_three:
    JMP the_beginning

div_by_two:
    JMP the_beginning

end:
    xor rax, rax
    ret
