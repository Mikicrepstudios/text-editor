#include <ncurses.h>

#include "internal.h"

void Render(struct Editor *editor) {
  // Get max number of rows and columns
  // size_t terminalWidth = getmaxx(stdscr); // Unused for now
  size_t terminalHeight = getmaxy(stdscr);

  move(0, 0); // Write text from start of screen

  // Offset to start_line
  struct LineNode *currentNode = editor->lines; // head of linked list
  for (size_t i = 0; i < editor->start_line && currentNode != NULL; i++) {
    currentNode = currentNode->next_line;
  }

  // Print lines until screen fills up or list ends
  for (size_t i = 0; i < terminalHeight && currentNode != NULL; i++) {
    printw("%s", currentNode->line_text); // print line + newline
    currentNode = currentNode->next_line;
  }

  free(currentNode);
}