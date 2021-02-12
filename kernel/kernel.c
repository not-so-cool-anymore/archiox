#define BLACK_BACKGROUND 0x07
#define WHITE_TEXT 0x07
#define GREEN_TEXT 0x02

#include "messages.h"
#include "vga/vga_handler.h"

int current_line = 0;

void kernel_main(void)
{

    // begining of the video memory
    char *video_memory_beggining_pointer = (char *)0xb8000;

    // 25 lines, 80 columns each, 2 bytes per char
    clear_screen(video_memory_beggining_pointer, BLACK_BACKGROUND);

    // prints init message
    write_string(video_memory_beggining_pointer, SUCCESSFUL_KERNEL_LOADING_MESSAGE, GREEN_TEXT, current_line);
    for (int i = 0; i < 8; i++)
    {
        write_new_line_string(video_memory_beggining_pointer, MADE_BY_SIGN[i], GREEN_TEXT, current_line);
    }
    return;
}

void keyboard_handler_init(void)
{
}