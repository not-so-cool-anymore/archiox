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

void write_string(char *video_memory_beggining_pointer, const char *string, int current_line)
{
    int memory_index = 80 * current_line * 2;
    int string_index = 0;

    while (string[string_index] != '\0')
    {
        video_memory_beggining_pointer[memory_index] = string[string_index];
        video_memory_beggining_pointer[memory_index + 1] = 0x02;
        ++string_index;
        memory_index = memory_index + 2;
    }
}

void write_new_line_string(char *video_memory_beggining_pointer, const char *string, int current_line)
{
}

void kernel_main(void)
{
    int current_line = 0;

    const char *opening_string = "The Kernel has been started successfully.";
    const char *sign_string_upper = "___________";
    const char *sing_string_text = "| By Ivan |";
    const char *sign_string_lower = "|_________|";
    const char *sing_string_stick = "     ||    ";

    // begining of the video memory
    char *video_memory_beggining_pointer = (char *)0xb8000;

    unsigned int i = 0;
    unsigned int j = 0;

    // 25 lines, 80 columns each, 2 bytes per char
    clear_screen(video_memory_beggining_pointer);

    write_string(video_memory_beggining_pointer, opening_string, current_line);

    return;
}
