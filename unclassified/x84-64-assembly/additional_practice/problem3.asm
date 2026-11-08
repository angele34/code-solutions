; Angel Arwen E. Reyes S30D
; NOTE: if user enters '-' at beginning of the string,
; the program defaults the error message to negative input.
; I have yet to add additional error checking to direct it to non-numeric input instead.

%include "io64.inc"

section .data
    var1 times 20 db 0      ; reserve up to 20 characters
    
section .text
global main
main:
    ; Prompt user for input
    PRINT_STRING "Input: "
    GET_STRING var1, 20     ; read input into var1 max of 20 characters
    PRINT_STRING var1
    xor rsi, rsi            ; let rsi = index of string
    xor eax, eax
    
check_chars:
    mov bl, [var1 + rsi]    ; move current char into BL
    
    cmp bl, 0               ; check if null terminator (end of string)
    JE done
    
    cmp bl, 0xA             ; check if user has entered
    JE done
    
    ;=====================================
    ;   Check if current char is negative
    ;=====================================
    cmp bl, '-'
    JE is_neg
    
    ;=====================================
    ; Check if current char is not numeric
    ;=====================================
    cmp bl, '0'
    JL not_numeric
    
    cmp bl, '9'
    JG not_numeric
    
    ; Convert ASCII char to numeric val
    sub bl, '0'
    
    ;========================================
    ; Convert char to num EAX: EAX = (EAX*10)
    ;========================================
    PUSH rdx                ; save rdx because multiplication messes with it
    mov edx, 10             ; set up multiplier 
    imul eax, edx           ; shift current total left by multiplying it by 10
    movzx edx, bl           ; put new digit from bl into edx
    add eax, edx            ; add new digit to total
    pop rdx                 ; restore original rdx value
    
    inc rsi
    jmp check_chars         ; loop till end of string
    
not_numeric:
    NEWLINE
    PRINT_STRING "Error: non-numeric input"
    JMP choice
    
is_neg:
    NEWLINE
    PRINT_STRING "Error: negative number input"
    JMP choice
    
choice:
    NEWLINE
    PRINT_STRING "Do you want to continue (Y/N)?: "
    
    GET_CHAR dil    ; Read Y/N input
    PRINT_CHAR dil
    NEWLINE
    
    CMP dil, 'Y'
    JE main
    CMP dil, 'y'
    JE main

    CMP dil, 'N'
    JE end
    CMP dil, 'n'
    JE end
    
    CMP dil, 0xA
    JE choice

    PRINT_STRING "Invalid choice. Please enter Y or N."
    NEWLINE
    JMP choice  
    
done:
    PRINT_STRING "Sequence: "
    xor r8b, r8b            ; let r8b = counter for sequences 
    
the_beginning:
    inc r8b 
    CMP r8b, 11
    JE choice               ; choose to end if have reached 10 sequences
    
    
    CMP r8b, 1              ; skip printing ',' if first num
    JE print_num
    PRINT_STRING ", "
    
print_num:
    PRINT_DEC 4, eax
    CMP eax, 1
    JE choice
    
    JMP valid
   
first_num:
    PRINT_DEC 4, eax
    JMP valid
end:
    xor rax, rax
    ret
valid:
    ; Store original value of eax in esi
    MOV ebx, eax  
    
    ; =======================================
    ; 1: Is it divisible by 3? (EAX % 3 == 0)
    ; =======================================
    ; If the integer is divisble by 3 -> divide it by three
    MOV ecx, 3
    XOR edx, edx
    DIV ecx ; eax / 3 (quotient in eax, remainder in edx)
    
    CMP edx, 0
    JE div_by_three ;  If remainder = 0
    
    ; =============================
    ; 2: Is it even? (EAX % 2 == 0)
    ; =============================
    ; If the integer is not divisble by three but is even -> divide it by two
    MOV eax, ebx
    MOV ecx, 2
    XOR edx, edx
    DIV ecx ; eax / 2
    
    CMP edx, 0
    JE div_by_two
    
    ; ============================
    ;        3: It is odd?
    ; ============================
    ; If the integer is not divisble by three but is odd -> multiply it by two and subtract one
    MOV eax, ebx    ; Restore original value
    IMUL eax, 2
    DEC eax    
       
    ; Repeat the process until the number reaches one or if it reaches ten sequences
    jmp the_beginning
    
div_by_three:
    ; Divisible by 3: DIV ecx already left the quotient in eax
    JMP the_beginning

div_by_two:
    ; Even: DIV ecx already left the quotient in eax
    JMP the_beginning