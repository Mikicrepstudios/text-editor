#include "internal.h"

#include <ncurses.h>
#include <stdio.h>

#include "frontend.h"
#include "internal.h"

int main() {
  struct Editor *editor = initialize_editor();

  switch_file(editor, "test.file");
  merge_line(editor, 5);

  initscr();
  noecho();
  keypad(stdscr, TRUE);

  while (running) {
    timeout(0); // Dont wait for input
    int ch = getch(); // Get user input

    Render(editor); // Render text and other elements
    move(editor.cursor_y_pos, editor.cursor_x_pos); // Render will mess up cursor position so just place it where it should be
    HandleInput(&editor, &running, ch); // Handles user input like moving cursor

    refresh();
  }

  move(0, 0);
  printw("Exited");
  getch();
  endwin();
  
	return 0;
}
