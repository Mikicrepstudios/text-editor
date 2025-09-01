#include "internal.h"

struct Editor *initialize_editor() {
  struct Editor *editor = malloc(sizeof(*editor));
  editor->curr_file_path = NULL;
  editor->cursor_x_pos = 0;
  editor->cursor_y_pos = 0;
  editor->lines = NULL;
  editor->start_line = 0;
  return editor;
}
