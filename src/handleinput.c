#include <stdbool.h>

#include "internal.h"

void HandleInput(struct Editor *editor, bool *running, int ch) {
    // e, exit
    if(ch == 101) *running = false;

    // h, move cursor left
    if(ch == 104 && editor->cursor_x_pos != 0) editor->cursor_x_pos -= 1;

    // j, move cursor down
    if(ch == 106) editor->cursor_y_pos += 1;

    // k, move cursor up
    if(ch == 107 && editor->cursor_y_pos != 0) editor->cursor_y_pos -= 1;

    // l, move cursor right
    if(ch == 108) editor->cursor_x_pos += 1;
}