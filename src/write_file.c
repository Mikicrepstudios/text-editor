#include "internal.h"
#include <stdio.h>

int8_t write_file(struct Editor *editor) {
  FILE *fptr = fopen(editor->curr_file_path, "w+");

  if (!fptr)
    return -1;

  for (struct LineNode* line = editor->lines; line != NULL; line = line->next_line) {
    fprintf(fptr, "%s", line->line_text);
  }

  fclose(fptr);
  return 0;
}
