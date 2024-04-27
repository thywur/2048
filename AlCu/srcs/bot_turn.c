#include "alcu.h"

#ifdef NCURSES
    int bot_turn_ncurses(t_vector *v, int count_on_line)
    {
        const char *format = "The bot takes %d items";
        int center = COLS / 2;
        int line = LINES - 2;
        int bot_take = 0;

        if (SHOULD_LOOSE(count_on_line))
        {
            if (N(count_on_line) % 4 == 0)
                bot_take = 1;
            else
                bot_take = (N(count_on_line)) % 4;
        }
        else
        {
            if (N(count_on_line) % 4 == 1)
                bot_take = 1;
            else
                bot_take = (N(count_on_line) - 1) % 4;
        }
        clear();
        draw_map(v, bot_take, 4);
        mvprintw(line, center - ft_strlen(format) / 2, format, bot_take);
        refresh();

        int ch = getch();
        if (ch == 27 || ch == 'q' || ch == 'Q')
        {
            return END_OF_FILE;
        }
        return (bot_take);
    }
#else
    int bot_turn_term(t_vector *v, int count_on_line)
    {
        int bot_take = 0;

        (void)v;
        if (SHOULD_LOOSE(count_on_line))
        {
            if (N(count_on_line) % 4 == 0)
                bot_take = 1;
            else
                bot_take = (N(count_on_line)) % 4;
        }
        else
        {
            if (N(count_on_line) % 4 == 1)
                bot_take = 1;
            else
                bot_take = (N(count_on_line) - 1) % 4;
        }
        ft_putstr("The Bot takes ");
        ft_putnbr(bot_take);
        ft_putendl(" items");
        return (bot_take);
    }
#endif

int bot_turn(t_vector *v, int count_on_line)
{
    #ifdef NCURSES
        return bot_turn_ncurses(v, count_on_line);
    #else
        return bot_turn_term(v, count_on_line);
    #endif
}

int find_strategy(t_vector *v)
{
    size_t i;
    int current;
    int prev;

    prev = ft_vector_get(v, 0);
    i = 1;
    while (i < v->count)
    {
        current = ft_vector_get(v, i);
        if (SHOULD_LOOSE(prev))
            SET_SHOULD_LOOSE_FLAG(current, N(prev) % 4 == 0);
        else
            SET_SHOULD_LOOSE_FLAG(current, N(prev) % 4 == 1);
        ft_vector_set(v, i, current);
        prev = current;
        i++;
    }
    return (0);
}
