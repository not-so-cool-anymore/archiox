global start
global keyboard_handler
global read_port
global write_port
global load_idt

extern kernel_main
exterm keyboard_handler_init

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

    load_itd:
        mov edx, [esp+4]
        lidt[edx]
        sti
        ret

    keyboard_handler:
        call keyboard_handler
        iretd

    read_port:
        mov edx, [esp+4]
        in al, dx
        ret

    write_port:
        mov edx, [esp+4]
        mov al, [esp+4+4]
        out dx, al
        ret
    