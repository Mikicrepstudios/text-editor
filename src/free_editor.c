#include "internal.h"

#include <stdio.h>
#include <stdlib.h>

void free_editor(struct Editor *editor) {
  struct LineNode *node = editor->lines;
  while (node != NULL) {
    struct LineNode *next_node = node->next_line;
    free(node->line_text);
    free(node);
    node = next_node;
  }
  free(editor);
}
