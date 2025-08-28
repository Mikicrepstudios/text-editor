#include "internal.h"

#include <stdio.h>
#include <ncurses.h>

int main() {
  struct Editor *editor = initialize_editor();
  if (!editor)
    return 1;

  int8_t status = switch_file(editor, "test.c");

  if (status != 0)
    perror("switch_file");

  status = write_to_buffer(editor, "Hello World!", sizeof("Hello World!"));

  if (status != 0)
    perror("write_to_buffer");

  status = write_file(editor);
  if (status != 0)
    perror("write_file");

  free(editor->buffer);
  free(editor);
	return 0;
}
