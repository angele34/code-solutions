%include "io64.inc"

; 5: Join 2 Datasets
section .data
    n dq 0
    m dq 0
    A times 100 dq 0
    B times 100 dq 0
    AB times 10100 dq 0
    output_length dq 0
section .text
global main
main:
    ;Read length of A
    xor rsi, rsi
    xor rdi, rdi
    PRINT_STRING "Inputs: "
    GET_DEC 8, [n]
    PRINT_DEC 8, [n]
read_A:
    ;read values of A
    cmp rsi, [n]
    jge done_read  ; if rsi >= length of A, move to read B
    
    GET_DEC 8, [A+rsi*8]
    PRINT_CHAR ' '
    PRINT_DEC 8, [A+rsi*8]
    
    inc rsi
    jmp read_A
done_read:
    GET_DEC 8, [m]
    PRINT_DEC 8, [m]
read_B:
    cmp rdi, [m]
    jge done
    
    GET_DEC 8, [B+rdi*8]
    PRINT_CHAR ' '
    PRINT_DEC 8, [B+rdi*8]
    
    inc rdi
    jmp read_B
done:
    xor rsi, rsi
    xor rdi, rdi
    
    xor r9, r9      ; counter for outer loop
    xor r8, r8      ; index of AB
join:
    xor rcx, rcx    ; counter for inner loop, resets every loop
    xor rdi, rdi
    ; move current value of a
    mov rax, [A+rsi*8]
    mov [AB+r8*8], rax
    
    inc r8
    
    ; move current value of B
    move_B:
        cmp rcx, [m]
        jge next_A
        
        mov rbx, [B+rdi*8]
        mov [AB+r8*8], rbx
        
        inc r8
        inc rdi
        inc rcx
        
        jmp move_B
next_A:
    inc rsi
    cmp rsi, [n]
    jl join

joined:
    NEWLINE
    mov rax, [m]
    inc rax
    imul rax, [n]
    mov [output_length],rax
    
    xor r8, r8
    
print_AB:
    cmp r8, [output_length]
    jge exit
    PRINT_DEC 8, [AB+r8*8]
    PRINT_CHAR ' '

    inc r8
    jmp print_AB
    
exit:
    xor rax, rax
    ret