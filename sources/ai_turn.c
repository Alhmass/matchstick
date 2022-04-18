/*
** EPITECH PROJECT, 2021
** ai_turn
** File description:
** ai_turn
*/

#include "lib.h"
#include "matchstick.h"
#include <stdlib.h>

int nb_taken_matches(game_data *game)
{
    int t_stick = total_stick_len(game->game_board);
    int m_matches = game->max_matches;
    int result = 0;

    result = t_stick - ((t_stick - 1) / (m_matches + 1) * (m_matches + 1) + 1);
    if (result < 1)
        result = 1;
    return (result);
}

void ai_turn(game_data *game)
{
    int nb_taken = nb_taken_matches(game);
    int line = line_enough_matches(nb_taken, game->game_board);

    if (line == 0) {
        nb_taken = 1;
        line = line_enough_matches(nb_taken, game->game_board);
    }
    delete_stick(ai, game->game_board, line, nb_taken);
}

int line_enough_matches(int nb_taken, char **game_board)
{
    for (int i = 1; game_board[i]; i++) {
        if (stick_len(game_board[i]) >= nb_taken)
            return (i);
    }
    return (0);
}
