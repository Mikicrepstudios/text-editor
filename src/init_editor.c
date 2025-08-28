#include "internal.h"

struct Editor* initialize_editor() {
  struct Editor *editor = calloc(1, sizeof(*editor));
  editor->buffer_capacity = 2;
  editor->buffer = calloc(sizeof(*editor->buffer), editor->buffer_capacity);
  return editor;
}
