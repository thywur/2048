#include "alcu.h"

#ifdef NCURSES
void draw_map_ncurses(t_vector *v, int to_take, int to_take_color)
{
    int center_x = COLS / 2;

    for (size_t i = 0; i < v->count; i++)
    {
        int row = LINES - 3 - (v->count - i);
        if (row < 0)
        {
            continue;
        }

        int num = ft_vector_get(v, i);
        int length = INI(num);
        int length_enabled = N(num);

        for (int j = 0; j < length; j++)
        {
            int col = center_x - length + (j * 2);
            int overflow = (length * 2) - COLS;
            int is_last_line = i == v->count - 1;
            int row_color_type = min(max(max(3 - (v->count - i - 1), 0), row), 3);
            int color_pair_index = 1;
            int is_used = (is_last_line && j >= length_enabled);
            int is_to_take = (is_last_line && j >= length_enabled - to_take);
            int dimmed = 0;
            char c = '|';

            if (overflow > 0)
            {
                if (COLS - ((length - length_enabled) * 2) > center_x)
                {
                    col = COLS - (length - j) * 2;
                    if (col < 2)
                    {
                        c = '<';
                    }
                }
                else if (length_enabled * 2 < center_x)
                {
                    col = j * 2;
                }
                else
                {
                    col = COLS - (length_enabled - j) * 2 - center_x;
                    if (col < 2)
                    {
                        c = '<';
                    }
                }
            }
            if (col < 0)
            {
                continue;
            }
            if (is_used)
            {
                row_color_type = 2;
                if (j - length_enabled < GET_LAST_TAKE(num))
                {
                    color_pair_index = GET_LAST_PLAYER(num) ? 6 : 5;
                }
            }

            if (row_color_type == 0)
            {
                color_pair_index = 2;
                dimmed = 1;
            }
            else if (row_color_type == 1)
            {
                color_pair_index = 2;
            }
            else if (row_color_type == 2)
            {
                dimmed = 1;
            }
            else if (is_to_take)
            {
                color_pair_index = to_take_color;
            }

            attron(COLOR_PAIR(color_pair_index) | (A_DIM * dimmed));
            mvaddch(row, col, c);
            attroff(COLOR_PAIR(color_pair_index) | (A_DIM * dimmed));
        }
    }
}
#else
void draw_map_term(t_vector *v, int to_take, int to_take_color)
{
    size_t i = 0;

    (void)to_take;
    (void)to_take_color;
    write(1, "\n", 1);
    while (i < v->count)
    {
        int line = N(ft_vector_get(v, i));
        for (int j = 0; j < line; j++)
        {
            write(1, "|", 1);
        }
        i++;
        write(1, "\n", 1);
    }
    write(1, "\n", 1);
}
#endif

void draw_map(t_vector *v, int to_take, int to_take_color)
{
#ifdef NCURSES
    draw_map_ncurses(v, to_take, to_take_color);
#else
    draw_map_term(v, to_take, to_take_color);
#endif
}
