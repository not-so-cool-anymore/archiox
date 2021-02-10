void kernel_main(void)
{
    const char *opening_string = "The Kernel has been started successfully.";
    char *video_memory_beggining_pointer = (char *)0xb8000;

    unsigned int i = 0;
    unsigned int j = 0;

    while (j < 80 * 25 * 2)
    {
        video_memory_beggining_pointer[j] = ' ';
        video_memory_beggining_pointer[j + 1] = 0x07;
        j = j + 2;
    }

    j = 0;

    while (opening_string[j] != '\0')
    {
        video_memory_beggining_pointer[i] = opening_string[j];
        video_memory_beggining_pointer[i + 1] = 0x02;
        ++j;
        i = i + 2;
    }

    return;
}