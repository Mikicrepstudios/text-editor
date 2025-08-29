#include <stdbool.h>

#include "internal.h"

void HandleInput(struct Editor *editor, bool *running, int ch) {
    switch(ch) {
        case 101: // E
            *running = false; // Stops program
            break;
        case 104: // H
            if(editor->cursor_x_pos != 0) editor->cursor_x_pos -= 1; // Move cursor left
            break;
        case 106: // J
            editor->cursor_y_pos += 1; // Move cursor down
            break;
        case 107: // K
            if(editor->cursor_y_pos != 0) editor->cursor_y_pos -= 1; // Move cursor up
            break;
        case 108: // L
            editor->cursor_x_pos += 1; // Move cursor right
            break;
    }
}