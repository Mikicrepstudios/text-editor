#include <stdio.h>
#include <ncurses.h>

#include "internal.h"

int main() {
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
}
// h 104 j 106 k 107 l 108