#define IDT_SIZE 256 // 256 available key interrupts

extern void keyboard_handler(void);
extern char read_port(unsigned short port);
extern void write_port(unsigned short port, unsigned char data);

struct IDT_descriptor
{
    unsigned short int offset_lowerbits;
    unsigned short int selector;
    unsigned char zero;
    unsigned char type_attr;
    unsigned short int offset_higherbits;
};

struct IDT_descriptor IDT[IDT_SIZE];

void init_idt(void)
{
    unsigned long idt_address;
    unsigned long idt_pointer[2];
    unsigned long keyboard_address;

    keyboard_address = (unsigned long)keyboard_handler;
    IDT[0x21].offset_lowerbits = keyboard_address & 0xffff;
    IDT[0x21].selector = 0x08;
    IDT[0x21].zero = 0;
    IDT[0x21].type_attr = 0x8e;
    IDT[0x21].offset_higherbits = (keyboard_address & 0xffff0000) >> 16;

    // Init ICW
    write_port(0x20, 0x11);
    write_port(0xA0, 0x11);

    // Remap ICW 2
    write_port(0x21, 0x20);
    write_port(0xA1, 0x28);
}