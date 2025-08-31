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

struct LineNode {
  struct LineNode *next_line;
  char *line_text;
  size_t line_capacity;
  size_t line_length;
};

struct Editor {
  struct LineNode *lines;
  char *curr_file_path;
  size_t start_line;
  size_t cursor_y_pos;
  size_t cursor_x_pos;
  //  unsigned char original_hash[256]; // A hash derived from the original file
  //  contents
  // This will be used to check whether a file was modified after you initialy
  // opened it
};

struct Editor *initialize_editor();
int8_t switch_file(struct Editor *editor, char *file_path);
int8_t write_file(struct Editor *editor);
int8_t move_cursor(struct Editor *editor, enum Directions dir);
int8_t change_line(struct Editor *editor, char *new_line, size_t new_line_size,
                   size_t line_index);
int8_t insert_line(struct Editor *editor, size_t index);
void free_editor(struct Editor *editor);

#endif
