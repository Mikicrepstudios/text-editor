#include "internal.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int8_t insert_line(struct Editor *editor, size_t index) {
  struct LineNode *line = editor->lines;
  size_t i;
  for (i = 0; i < index && line != NULL; ++i)
    line = line->next_line;

  if (i != index)
    return ERR_OUB;

  struct LineNode *new_line = malloc(sizeof(*new_line));

  new_line->line_capacity = 1;
  new_line->line_length = 0;
  new_line->line_text = malloc(new_line->line_capacity);
  new_line->line_text[0] = '\0';
  new_line->next_line = line->next_line;

  line->next_line = new_line;

  return SUCCESS;
}
