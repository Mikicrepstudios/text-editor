#include "internal.h"

#include <ncurses.h>
#include <stdio.h>

#include "internal.h"

int main() {
  struct Editor *editor = initialize_editor();

  switch_file(editor, "test.file");
  merge_line(editor, 5);

  for (struct LineNode *line = editor->lines; line; line = line->next_line)
    puts(line->line_text);


  // editor.cursor_x_pos = 0;
  // editor.cursor_y_pos = 0;

  // initscr();
  // noecho();

  // while (running) {
  //   int ch = getch(); // Get user input

  //  // e, exit
  //  if(ch == 101) running = false;

  //  // h, move cursor left
  //  if(ch == 104 && editor.cursor_x_pos != 0) editor.cursor_x_pos -= 1;

  //  // j, move cursor down
  //  if(ch == 106) editor.cursor_y_pos += 1;

  //  // k, move cursor up
  //  if(ch == 107 && editor.cursor_y_pos != 0) editor.cursor_y_pos -= 1;
  //  // l, move cursor right
  //  if(ch == 108) editor.cursor_x_pos += 1;

  //  move(editor.cursor_y_pos, editor.cursor_x_pos);
  //  refresh();
  //}
  //
  // move(0, 0);
  // printw("Exited");
  // getch();
  // endwin();
  free_editor(editor);
  return 0;
}
// h 104 j 106 k 107 l 108
