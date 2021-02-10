global  _start

extern  kernel_main
bits    32

section .bss
    resb 8192
    stack_space:


section .text
    _start:
        cli
        mov esp, stack_space
        call kernel_main
        hlt

