%include "io64.inc"
section .text
global CMAIN
CMAIN:
    PRINT_STRING "Hello World"
    NEWLINE
    PRINT_STRING "Welcome to LBYARCH"
    NEWLINE
    
    PRINT_CHAR 'A'
    NEWLINE
    PRINT_CHAR 65
    NEWLINE
    PRINT_CHAR 64+1
    NEWLINE
    PRINT_CHAR 'ABC'
    NEWLINE
    
    PRINT_HEX 8, 10b     
    NEWLINE 
    PRINT_HEX 8, 10o 
    NEWLINE 
    PRINT_HEX 8, 10d 
    NEWLINE     
    PRINT_HEX 8, 10 
    NEWLINE
    
    NEWLINE     
    PRINT_HEX 8, 10h 
    NEWLINE 
    PRINT_HEX 8, 0x10 
    NEWLINE     
    PRINT_HEX 8, 10b+10o+10d+10h 
    NEWLINE
    
    NEWLINE
    PRINT_DEC 8, 123 
    NEWLINE 
    PRINT_DEC 8, -123 
    NEWLINE 
    PRINT_DEC 8, 10+20-30*40/50 
    NEWLINE
    
    NEWLINE
    PRINT_DEC 2, 32767     
    NEWLINE 
    PRINT_DEC 2, 32768 
    NEWLINE 
    PRINT_UDEC 2, 65535 
    NEWLINE 
    PRINT_UDEC 2, 65536 
    NEWLINE
    
    NEWLINE
    PRINT_DEC 1, 127    
    NEWLINE 
    PRINT_DEC 1, 128 
    NEWLINE 
    PRINT_UDEC 1, 255 
    NEWLINE 
    PRINT_UDEC 1, 256 
    
    xor rax, rax
    ret