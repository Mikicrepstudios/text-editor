#include "internal.h"

struct LineNode *get_line(struct Editor *editor, size_t index) {
  size_t i;
  struct LineNode *line = editor->lines;
  for (i = 0; line && i < index; ++i, line = line->next_line)
    ;
  if (i != index)
    return NULL;
  return line;
}
