#include <stdio.h>

#include "internal.h"


int8_t switch_file(struct Editor *editor, char *file_path) {
  FILE* fptr = fopen(file_path, "ab+"); // Open file with read permissions
  if (!fptr)
    return -1;

  // Get the size of the file in bytes
  fseek(fptr, 0L, SEEK_END);
  size_t file_size = ftell(fptr);
  rewind(fptr);

  editor->buffer_capacity = file_size;
  editor->buffer_size = 0;

  // If memory was already allocated for the buffer, free it
  if (editor->buffer != NULL)
    free(editor->buffer);

  editor->buffer = malloc(editor->buffer_capacity + 1);

  if (!editor->buffer) {
    fclose(fptr);
    return -1;
  }

  size_t len = fread(editor->buffer, 1, sizeof(*editor->buffer) * editor->buffer_capacity, fptr);

  editor->buffer[len] = '\0';

  editor->curr_file_path = file_path;

  fclose(fptr);
  return 0;
}
