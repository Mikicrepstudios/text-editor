#ifndef INTERNAL_EDITR_H
#define INTERNAL_EDITR_H

#include <stdint.h>
#include <stdlib.h>

enum Directions {
  UP = 0,
  RIGHT,
  DOWN,
  LEFT,
};

struct Editor {
  char *buffer;
  char *curr_file_path;
  size_t start_line;
  size_t cursor_y_pos;
  size_t cursor_x_pos;
  size_t buffer_size;
  size_t buffer_capacity;
};

struct Editor* initialize_editor();
int8_t switch_file(struct Editor *editor, char *file_path);
int8_t write_file(struct Editor *editor);
int8_t move_cursor(struct Editor *editor, enum Directions dir);
int8_t write_to_buffer(struct Editor *editor, char* data, size_t size);

#endif
