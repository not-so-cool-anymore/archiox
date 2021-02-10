#define BLACK_BACKGROND 0x07
#define WHITE_TEXT 0x07
#define GREEN_TEXT 0x02

int current_line = 0;

void clear_screen(char *video_memory_beggining_pointer)
{
    int j = 0;
    while (j < 80 * 25 * 2)
    {
        video_memory_beggining_pointer[j] = ' ';
        video_memory_beggining_pointer[j + 1] = 0x07;
        j = j + 2;
    }
}

void write_string(char *video_memory_beggining_pointer, const char *string, int color)
{
    int memory_index = 80 * current_line * 2;
    int string_index = 0;

    while (string[string_index] != '\0')
    {
        video_memory_beggining_pointer[memory_index] = string[string_index];
        video_memory_beggining_pointer[memory_index + 1] = color;
        ++string_index;
        memory_index = memory_index + 2;
    }
}

void write_new_line_string(char *video_memory_beggining_pointer, const char *string, int color)
{
    ++current_line;
    write_string(video_memory_beggining_pointer, string, color);
}

void kernel_main(void)
{
    const char *opening_string = "                   The Kernel has been loaded successfully.                     ";

    const char *sign[] = {
        "                                   __________                                   ",
        "                                  |    By    |                                  ",
        "                                  |   Ivan   |                                  ",
        "                                  |__________|                                  ",
        "                                       ||                                       ",
        "                                       ||                                       ",
        "                                       ||                                       ",
        "                                       ==                                       ",

    };

    // begining of the video memory
    char *video_memory_beggining_pointer = (char *)0xb8000;

    // 25 lines, 80 columns each, 2 bytes per char
    clear_screen(video_memory_beggining_pointer);

    // prints init message
    write_string(video_memory_beggining_pointer, opening_string, GREEN_TEXT);
    for (int i = 0; i < 8; i++)
    {
        write_new_line_string(video_memory_beggining_pointer, sign[i], GREEN_TEXT);
    }
    return;
}
