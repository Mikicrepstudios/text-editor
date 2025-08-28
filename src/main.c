#include <stdio.h>
#include <ncurses.h>

int main() {
  initscr();
  noecho();
  printw("Hello World!");
  getch();
  refresh();
  refresh();
  getch();
  endwin();
	return 0;
}
