#ifndef INTERNAL_EDITR_H
#define INTERNAL_EDITR_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define PRIME_HASH_NUMBER 179

enum Errors {
  SUCCESS = 0,    // No error
  ERR_ERRNO = -1, // Error is handled by errno
  ERR_OUB,        // Out of bounds error
}; // Helper enum to define some errors for error handling
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
  uint64_t original_hash; // A hash derived from the original file
  //  contents
  // This will be used to check whether a file was modified after you initialy
  // opened it
};

struct Editor *initialize_editor();
struct LineNode *get_line(struct Editor *editor, size_t index);
int8_t switch_file(struct Editor *editor, char *file_path);
int8_t write_file(struct Editor *editor);
int8_t move_cursor(struct Editor *editor, enum Directions dir);
int8_t change_line(struct Editor *editor, char *new_line, size_t new_line_size,
                   size_t line_index);
int8_t insert_line(struct Editor *editor, size_t index);
int8_t merge_line(struct Editor *editor,
                  size_t merging_line); // Merges a line with the line before it
int8_t has_changed(
    struct Editor
        *editor); // Checks whether or not the file in question has changed due
                  // to another program The return value is 0 if false, 1 if
                  // true, all non-positive values are errors
void free_editor(struct Editor *editor);

#endif
