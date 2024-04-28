#include "wkw.h"

static int set_cursed_values()
{
    if (curs_set(0) == ERR)
        return 1;
    raw();
    if (keypad(stdscr, TRUE) == ERR)
        return 1;
    if (set_escdelay(50))
        return 1;
    if (nodelay(stdscr, TRUE) == ERR)
        return 1;
    if (!can_change_color() || !has_colors())
        return 1;
    if (start_color() == ERR)
        return 1;
    if (init_pair(1, COLOR_WHITE, COLOR_BLACK) == ERR)
        return 1;
    if (init_pair(2, COLOR_CYAN, COLOR_BLACK) == ERR)
        return 1;
    if (init_pair(3, COLOR_RED, COLOR_BLACK) == ERR)
        return 1;
    if (init_pair(4, COLOR_BLACK, COLOR_CYAN) == ERR)
        return 1;
    if (init_pair(5, COLOR_BLACK, COLOR_RED) == ERR)
        return 1;
    if (init_pair(6, COLOR_BLACK, COLOR_BLUE) == ERR)
        return 1;
    if (init_pair(7, COLOR_BLACK, COLOR_GREEN) == ERR)
        return 1;
    if (init_pair(8, COLOR_BLACK, COLOR_MAGENTA) == ERR)
        return 1;
    if (init_pair(9, COLOR_BLACK, COLOR_YELLOW) == ERR)
        return 1;
    if (init_pair(10, COLOR_BLACK, COLOR_WHITE) == ERR)
        return 1;
    timeout(1000);
    return 0;
}

int init_ncurses(WINDOW *stdscr)
{
    setlocale(LC_ALL, "");
    stdscr = initscr();
    if (!stdscr)
        return 1;
    if (set_cursed_values())
    {
        endwin();
        return 1;
    }
    return 0;
}
