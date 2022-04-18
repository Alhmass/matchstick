/*
** EPITECH PROJECT, 2021
** matchstick.
** File description:
** matchstick
*/

#include "lib.h"
#include "matchstick.h"
#include <stdlib.h>

int matchstick(game_data *game)
{
    int actual_player = player;
    int status = 1;

    while (game->game_status == 0) {
        if (status == 0) return (0);
        print_tab_char(game->game_board);
        my_putstr("\n");
        if (actual_player == player) {
            my_putstr("Your turn:\n");
            status = player_turn(game);
            actual_player = ai;
        }
        else if (actual_player == ai) {
            my_putstr("AI's turn...\n");
            ai_turn(game);
            actual_player = player;
        } verif_game_status(game, actual_player);
    }
    end_message(actual_player, game);
    tab_char_free(game->game_board);
    return (game->game_status);
}

void end_message(int actual_player, game_data *game)
{
    print_tab_char(game->game_board);
    if (actual_player == ai)
        my_putstr("You lost, too bad...\n");
    else if (actual_player == player)
        my_putstr("I lost... snif... but I'll get you next time!!\n");
}

void verif_game_status(game_data *game, int actual_player)
{
    if (total_stick_len(game->game_board) == 0)
        game->game_status = actual_player;
}

char *get_player_entry(void)
{
    char *str;
    size_t input_size = 10;
    char **str_ptr = &str;

    str = malloc(sizeof(char) * input_size);
    if (str == NULL)
        return (NULL);
    if (getline(str_ptr, &input_size, stdin) == -1)
        return (NULL);
    return (str);
}
