#include "internal.h"
#include <stdio.h>
#include <string.h>

int8_t write_to_buffer(struct Editor *editor, char *data, size_t size) {
  if (editor->buffer_capacity < size) {
    if (editor->buffer_capacity < 1)
      editor->buffer_capacity = 1;
    // Double the size of the buffer until it is greater than the size written
    // to if
    while (editor->buffer_capacity < size) {
      printf("%zu\n", size);
      editor->buffer_capacity *= 2;
    }
    char *data_tmp = realloc(editor->buffer, editor->buffer_capacity);
    if (!data_tmp)
      return -1;
    editor->buffer = data_tmp;
  }

  strncpy(editor->buffer, data, size);
  editor->buffer_size = size;

  return 0;
}
