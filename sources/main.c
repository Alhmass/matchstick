/*
** EPITECH PROJECT, 2021
** main.
** File description:
** main
*/

#include "matchstick.h"

int main(int ac, char **argv)
{
    game_data *game;

    if (ac < 3)
        return (0);
    else if ((game = init_struct(argv + 1)) == NULL)
        return (0);
    return (matchstick(game));
}
