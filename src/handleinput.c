#include <stdbool.h>
#include <ncurses.h>

#include "frontend.h"
#include "internal.h"

void HandleInput(struct Editor *editor, bool *running, int ch) {
    switch(ch) {
        //case 104: // H
        case KEY_LEFT:
            if(editor->cursor_x_pos != 0) editor->cursor_x_pos -= 1; // Move cursor left
            break;
        //case 106: // J
        case KEY_DOWN:
            editor->cursor_y_pos += 1; // Move cursor down
            break;
        //case 107: // K
        case KEY_UP:
            if(editor->cursor_y_pos != 0) editor->cursor_y_pos -= 1; // Move cursor up
            break;
        //case 108: // L
        case KEY_RIGHT:
            editor->cursor_x_pos += 1; // Move cursor right
            break;

        default:
            HandleEditing(&editor, ch);
    }
}