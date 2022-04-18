/*
** EPITECH PROJECT, 2021
** player_turn.
** File description:
** player_turn
*/

#include "lib.h"
#include "matchstick.h"
#include <stdlib.h>

int player_turn(game_data *game)
{
    int line = 0;
    int matches = 0;

    line = line_entry(game);
    if (line == -2)
        return (0);
    if (line == -1)
        return (player_turn(game));
    matches = matches_entry(line, game);
    if (matches == -2)
        return (0);
    else if (matches == -1)
        return (player_turn(game));
    else {
        delete_stick(player, game->game_board, line, matches);
        return (1);
    }
}

int verif_matches_line(char *matches_entry, int line, game_data *game)
{
    if (my_getnbr(matches_entry) > game->max_matches) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(game->max_matches);
        my_putstr(" matches per turn\n");
        return (-1);
    }
    else if (my_getnbr(matches_entry) > stick_len(game->game_board[line])) {
        my_putstr("Error: not enough matches on this line\n");
        return (-1);
    }
    return (0);
}

int line_entry(game_data *game)
{
    char *line_entry;

    my_putstr("Line: ");
    line_entry = get_player_entry();
    if (line_entry == NULL)
        return (-2);
    else if (verif_entry(line_entry) == 1)
        return (-1);
    else if (my_getnbr(line_entry) == 0
            || my_getnbr(line_entry) > game->nb_lines) {
        my_putstr("Error: this line is out of range\n");
        return (-1);
    }
    return (my_getnbr(line_entry));
}

int verif_entry(char *entry)
{
    for (int i = 0; entry[i] != '\0'; i++) {
        if (entry[i] >= '0' && entry[i] <= '9')
            continue;
        else if (entry[i] == '\n')
            continue;
        else {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (1);
        }
    }
    return (0);
}
