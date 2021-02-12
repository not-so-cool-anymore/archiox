#ifndef VGA_HANDLER_H_
#define VGA_HANDLER_H_

void clear_screen(char *video_memory_beggining_pointer, int background_color);
void write_string(char *video_memory_beggining_pointer, const char *string, int color, int *current_line);
void write_string(char *video_memory_beggining_pointer, const char *string, int color, int *current_line);

#endif