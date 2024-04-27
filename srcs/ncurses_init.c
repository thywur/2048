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
    // if (assume_default_colors(COLOR_WHITE, COLOR_BLACK) == ERR) // Noir / Blanc
    //     return 1;
    if (init_pair(1, COLOR_WHITE, COLOR_BLACK) == ERR) // Noir / Blanc
        return 1;
    if (init_pair(2, COLOR_CYAN, COLOR_BLACK) == ERR) // Noir / Cyan
        return 1;
    if (init_pair(3, COLOR_RED, COLOR_BLACK) == ERR) // Noir / Rouge
        return 1;
    if (init_pair(4, COLOR_BLACK, COLOR_CYAN) == ERR) // Noir / Cyan
        return 1;
    if (init_pair(5, COLOR_BLACK, COLOR_RED) == ERR) // Noir / Rouge
        return 1;
    if (init_pair(6, COLOR_BLACK, COLOR_BLUE) == ERR) // Noir / Bleu
        return 1;
    if (init_pair(7, COLOR_BLACK, COLOR_GREEN) == ERR) // Noir / Vert
        return 1;
    if (init_pair(8, COLOR_BLACK, COLOR_MAGENTA) == ERR) // Noir / Magenta
        return 1;
    if (init_pair(9, COLOR_BLACK, COLOR_YELLOW) == ERR) // Noir / Jaune
        return 1;
    // if (init_pair(4, COLOR_WHITE, COLOR_RED) == ERR) // Blanc / Rouge
    //     return 1;
    // if (init_pair(6, COLOR_GREEN, COLOR_BLACK) == ERR) // Vert / Noir
    //     return 1;
    // if (init_pair(7, COLOR_MAGENTA, COLOR_BLACK) == ERR) // Magenta / Noir
    //     return 1;
    // if (init_pair(9, COLOR_BLUE, COLOR_BLACK) == ERR) // Bleu / Noir
    //     return 1;
    // if (init_pair(10, COLOR_YELLOW, COLOR_BLACK) == ERR) // Jaune / Noir
    //     return 1;
    // if (init_pair(2, 8, COLOR_BLACK) == ERR) // Gris / Noir
    //     return 1;
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
