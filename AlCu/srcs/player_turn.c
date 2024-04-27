#include "alcu.h"

#ifdef NCURSES
static int player_turn_ncurses(t_vector *v, int count_on_line)
{
    const char *format = "Please choose between 1 and %d items";

    int max_to_remove = min(3, count_on_line);
    int to_take = 1;
    while (1)
    {
        int center = COLS / 2;
        int line = LINES - 2;

        clear();
        draw_map(v, to_take, 3);
        mvprintw(line, center - ft_strlen(format) / 2, format, max_to_remove);
        refresh();

        int ch = getch();
        if (ch == 27 || ch == 'q' || ch == 'Q')
        {
            return END_OF_FILE;
        }
        else if (ch == KEY_UP)
        {
            to_take = min(to_take + 1, max_to_remove);
        }
        else if (ch == KEY_DOWN)
        {
            to_take = max(to_take - 1, 1);
        }
        else if (ch == KEY_ENTER || ch == KEY_RIGHT || ch == 10)
        {
            break;
        }
        else if (ch == '1' || ch == '2' || ch == '3')
        {
            to_take = min(ch - '0', max_to_remove);
        }
    }
    return to_take;
}
#else
static int player_turn_term(t_vector *v, int count_on_line)
{
    int max_to_remove = min(3, count_on_line);

    (void)v;
    ft_putstr("Please choose between 1 and ");
    ft_putnbr(max_to_remove);
    ft_putendl(" items");
    int choosen = atoi_from_read(0, min(3, max_to_remove));
    while (choosen == ERROR || choosen == EMPTY)
    {
        ft_putendl("Invalid choice");
        choosen = atoi_from_read(0, min(3, max_to_remove));
    }

    if (choosen == END_OF_FILE)
        return END_OF_FILE;
    return choosen;
}
#endif

int player_turn(t_vector *v, int count_on_line)
{
#ifdef NCURSES
    return player_turn_ncurses(v, count_on_line);
#else
    return player_turn_term(v, count_on_line);
#endif
}
