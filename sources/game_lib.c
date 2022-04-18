/*
** EPITECH PROJECT, 2021
** game_lib
** File description:
** game_lib
*/

#include "lib.h"
#include "matchstick.h"
#include <stdlib.h>

void delete_stick(int actual_player, char **game_board, int line, int nb_stick)
{
    int end_line = my_strlen(game_board[line]);
    int stick_to_rm = nb_stick;

    while (stick_to_rm != 0)
    {
        while (game_board[line][end_line] != '|')
            end_line--;
        game_board[line][end_line] = ' ';
        stick_to_rm--;
        end_line--;
    }
    print_remove_message(actual_player, line, nb_stick);
}

void print_remove_message(int actual_player, int line, int nb_stick)
{
    if (actual_player == player)
        my_putstr("Player removed ");
    else if (actual_player == ai)
        my_putstr("AI removed ");
    my_put_nbr(nb_stick);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int stick_len(char *line)
{
    int nb_stick = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '|')
            nb_stick++;
    }
    return (nb_stick);
}

int total_stick_len(char **game_board)
{
    int total_stick = 0;

    for (int i = 0; game_board[i] != NULL; i++) {
        total_stick += stick_len(game_board[i]);
    }
    return (total_stick);
}
