#include "internal.h"
#include <stdio.h>

int8_t write_file(struct Editor *editor) {
  puts(editor->curr_file_path);
  FILE *fptr = fopen(editor->curr_file_path, "w+");

  if (!fptr)
    return -1;

  printf("cacacity: %zu\n", editor->buffer_capacity);
  fwrite(editor->buffer, 1, editor->buffer_size, fptr);
  puts(editor->buffer);

  fclose(fptr);
  return 0;
}
