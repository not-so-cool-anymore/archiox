
void clear_screen(char *video_memory_beggining_pointer, int background_color)
{
    int j = 0;
    while (j < 80 * 25 * 2)
    {
        video_memory_beggining_pointer[j] = ' ';
        video_memory_beggining_pointer[j + 1] = background_color;
        j = j + 2;
    }
}

void write_string(char *video_memory_beggining_pointer, const char *string, int color, int *current_line)
{
    int memory_index = 80 * (*current_line) * 2;
    int string_index = 0;

    while (string[string_index] != '\0')
    {
        video_memory_beggining_pointer[memory_index] = string[string_index];
        video_memory_beggining_pointer[memory_index + 1] = color;
        ++string_index;
        memory_index = memory_index + 2;
    }
}

void write_new_line_string(char *video_memory_beggining_pointer, const char *string, int color, int *current_line)
{
    ++current_line;
    write_string(video_memory_beggining_pointer, string, color, current_line);
}