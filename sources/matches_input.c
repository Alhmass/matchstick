/*
** EPITECH PROJECT, 2021
** matches_input.
** File description:
** matches_input
*/

#include "lib.h"
#include "matchstick.h"
#include <stdlib.h>

int matches_entry(int line, game_data *game)
{
    char *matches_entry;
    int status = 0;

    my_putstr("Matches: ");
    matches_entry = get_player_entry();
    if (matches_entry == NULL)
        return (-2);
    else if (verif_entry(matches_entry) == 1)
        return (-1);
    status = verif_matches_input(matches_entry, line, game);
    if (status != 1)
        return (status);
    return (my_getnbr(matches_entry));
}

int verif_matches_input(char *matches_entry, int line, game_data *game)
{
    if (my_getnbr(matches_entry) == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (-1);
    }
    else if (verif_matches_line(matches_entry, line, game) == -1)
        return (-1);
    else
        return (1);
}
