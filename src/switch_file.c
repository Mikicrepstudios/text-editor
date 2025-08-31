#include <stdio.h>
#include <string.h>

#include "internal.h"

int8_t switch_file(struct Editor *editor, char *file_path) {
  FILE *fptr = fopen(file_path, "ab+"); // Open file with read permissions
  if (!fptr)
    return -1;

  ssize_t read;
  size_t len = 0;
  char *line = NULL;

  editor->lines = malloc(sizeof(*editor->lines));
  struct LineNode *node = editor->lines;

  if (!node) {
    fclose(fptr);
    return -1;
  }

  struct LineNode *prev_node = node;
  while ((read = getline(&line, &len, fptr)) != -1) {
    node->line_length = read;
    node->line_capacity = read;
    node->line_text = malloc(len);
    strncpy(node->line_text, line, len);
    node->next_line = malloc(sizeof(*editor->lines));
    if (!node->next_line) {
      fclose(fptr);
      return -1;
    }
    prev_node = node;
    node = node->next_line;
  }

  free(line);
  free(node);

  prev_node->next_line = NULL;

  editor->curr_file_path = file_path;

  fclose(fptr);
  return 0;
}
