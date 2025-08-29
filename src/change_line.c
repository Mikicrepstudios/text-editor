#include "internal.h"
#include <stdio.h>
#include <string.h>

int8_t change_line(struct Editor *editor, char *new_line, size_t new_line_size, size_t line_index) {
  struct LineNode *line = editor->lines;
  for (size_t _ = 0; _ < line_index; ++_) {
    line = line->next_line;
  }

  strncpy(line->line_text, new_line, new_line_size);
  
  return 0;
}
