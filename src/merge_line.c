#include "internal.h"

#include <stdint.h>
#include <string.h>

int8_t merge_line(struct Editor *editor, size_t merging_line) {
  struct LineNode *line = editor->lines;
  size_t i; // Index of the line before merging_line
  for (i = 0; i + 1 < merging_line && line->next_line;
       line = line->next_line, ++i)
    ;

  struct LineNode *next_line = line->next_line;

  if (i + 1 != merging_line || next_line == NULL || next_line->next_line == NULL)
    return -1;

  line->line_text =
      realloc(line->line_text,
              strlen(line->line_text) + strlen(next_line->line_text) + 1);

  strcat(line->line_text, next_line->line_text);

  line->next_line = next_line->next_line;

  free(next_line->line_text);
  free(next_line);

  return 0;
}
