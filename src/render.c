#include <ncurses.h>

#include "internal.h"

void Render(struct Editor editor) {
    // Get max number of rows and columns
    size_t terminalWidth = getmaxx(stdscr);
    size_t terminalHeight = getmaxy(stdscr);

    //// UNTESTED - MIGHT NOT WORK ////
    struct LineNode *currentNode = &editor.lines; // Linked list with text

    move(0, 0); // Write text from start of screen

    // Offset to start_line
    for (size_t i = 0; i < editor.start_line && currentNode != NULL; i++) {
        currentNode = currentNode->next_line;
    }

    // Print rest of stuff all the way till terminalHeight
    for (size_t i = 0; i < terminalHeight && currentNode != NULL; i++) {
        printw("%s", currentNode->line_text);
        currentNode = currentNode->next_line; // Go to next node
    }
}