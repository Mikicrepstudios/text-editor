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
  char* buffer;
  char* curr_file_path;
  size_t start_line;
  size_t cursor_y_pos;
  size_t cursor_x_pos;
  size_t buffer_size;
  size_t buffer_capacity;
};

// We return an 8-bit integer as a status code
// Everything which isn't 0 is an error
int8_t change_file(struct Editor, char* file_path);
int8_t write_file(struct Editor);
int8_t move_cursor(struct Editor, enum Directions dir);

#endif
