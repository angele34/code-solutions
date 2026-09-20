%include "io64.inc"
section .text
global main
main:
    ; registers are storage found inside processor
    ; faster because its same place with the processor
    ; no need to declare
    ; registers (64-bit) : RAX,RBX,RCX,RDX, R8,R9,R10,R11,R12,R13,R14,R15,
    ; RSI, RDI, RBP      / RSP, RIP / rflags
    ; RAX (64-bit),  EAX (32-bit), AX (16-bit), AH, AL (8-bit)
    ; RBX (64-bit),  EBX (32-bit), BX (16-bit), BH, BL (8-bit)
    ; R8-R15 exclusive x86-64 (64-bit programming)
    ; R8 (64), R8D (32), R8W (16), R8B (8) bits
    ; RSI (64), ESI(32), SI(16), SIL(8)
    ; RSP (stack pointer) - always points to the top of stack
    ; RIP (instruction pointer) - always points to the next instruction to be fetched
    
    ; except for 32-bit version | 16-bit and 8-bit are subset of 64-bit register
    
    mov rax, 0x12345678abcd_ef_10
    ;al - 0x10
    ;ah - 0xef
    ;ax - 0xef10
    ;eax - 0xabcdef10
    
    mov r8, 0x12345678abcd_ef_10
    ;r8b - 0x10
    ;r8w - 0xef10
    ;r8d - 0xabcdef10
    
    mov rsi, 0x12345678abcd_ef_10
    ;sil - 0x10
    ;si - 0xef10
    ;esi - 0xabcdef10
    mov sil, 0x22
    
    mov rbp, 0x12345678abcd_ef_10
    ;bpl - 0x10
    ;bp - 0xef10
    ;ebp - 0xabcdef10
    mov bpl, 0x22
    
    xor rax, rax
    ret