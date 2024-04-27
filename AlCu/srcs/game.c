#include "alcu.h"

int game_loop(t_vector *v)
{
    int is_player_turn = 0;

    if (welcome_screen(v) == END_OF_FILE)
        return END_OF_FILE;

    while (v->count > 0)
    {
        int count_on_line = ft_vector_get(v, v->count - 1);

        int choosen;
        if (is_player_turn)
            choosen = player_turn(v, N(count_on_line));
        else
            choosen = bot_turn(v, count_on_line);

        if (choosen == END_OF_FILE)
            return END_OF_FILE;

        count_on_line -= choosen;
        SET_LAST_PLAYER_FLAG(count_on_line, is_player_turn);
        SET_LAST_TAKE_COUNT(count_on_line, choosen);
        ft_vector_set(v, v->count - 1, count_on_line);
        if (N(count_on_line) == 0)
            v->count--;

        #ifndef NCURSES
            draw_map(v, 0, 0);
        #endif

        is_player_turn = !is_player_turn;
    }

    end_screen(is_player_turn);

    return EMPTY;
}
