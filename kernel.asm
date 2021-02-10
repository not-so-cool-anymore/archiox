global start
extern kernel_main

bits 32

section .bss
    resb 8096		
    stack_space:

section .text
    align 4
    dd 0x1BADB002
    dd 0x00
    dd - (0x1BADB002 + 0x00)

    start:
    cli
    mov esp, stack_space
    call kernel_main
    hlt
