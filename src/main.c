#include <stdio.h>
#include <ncurses.h>

#include "frontend.h"
#include "internal.h"

int main() {
  bool running = true;
  struct Editor editor = {};

  editor.cursor_x_pos = 0;
  editor.cursor_y_pos = 0;

  initscr();
  noecho();
  keypad(stdscr, TRUE);

  while (running) {
    int ch = getch(); // Get user input

    Render();
    HandleInput(&editor, &running, ch); // Handles user input like moving cursor

    move(editor.cursor_y_pos, editor.cursor_x_pos);
    refresh();
  }

  move(0, 0);
  printw("Exited");
  getch();
  endwin();
	return 0;
}
// h 104 j 106 k 107 l 108