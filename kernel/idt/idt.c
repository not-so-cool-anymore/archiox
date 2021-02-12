#define IDT_SIZE 256 // 256 available key interrupts

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
}