#include "internal.h"

#include <ncurses.h>
#include <stdio.h>

int main() {
  struct Editor *editor = initialize_editor();
  if (!editor)
    return 1;

  int8_t status = switch_file(editor, "test.c");

  if (status != 0)
    perror("switch_file");

  status = change_line(editor, "Hello World!", sizeof("Hello World!"), 1);

  if (status != 0)
    perror("write_to_buffer");

  editor->curr_file_path = "poop.file";
  status = write_file(editor);
  if (status != 0)
    perror("write_file");

  struct LineNode *node = editor->lines;

  while (node != NULL) {
    puts(node->line_text);
    struct LineNode *next_node = node->next_line;
    free(node->line_text);
    free(node);
    node = next_node;
  }

  free(editor);
  return 0;
}
