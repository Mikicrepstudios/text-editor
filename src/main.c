#include "internal.h"

#include <ncurses.h>
#include <stdio.h>

#include "internal.h"

int main() {
<<<<<<< HEAD
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
=======
  bool running = true;
  struct Editor editor = {};

  editor.cursor_x_pos = 0;
  editor.cursor_y_pos = 0;

  initscr();
  noecho();

  while (running) {
    int ch = getch(); // Get user input

    // e, exit
    if(ch == 101) running = false;

    // h, move cursor left
    if(ch == 104 && editor.cursor_x_pos != 0) editor.cursor_x_pos -= 1;

    // j, move cursor down
    if(ch == 106) editor.cursor_y_pos += 1;

    // k, move cursor up
    if(ch == 107 && editor.cursor_y_pos != 0) editor.cursor_y_pos -= 1;

    // l, move cursor right
    if(ch == 108) editor.cursor_x_pos += 1;

    move(editor.cursor_y_pos, editor.cursor_x_pos);
    refresh();
  }
  
  move(0, 0);
  printw("Exited");
  getch();
  endwin();
	return 0;
>>>>>>> origin
}
// h 104 j 106 k 107 l 108