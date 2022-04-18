/*
** EPITECH PROJECT, 2021
** game_board.
** File description:
** game_board
*/

#include "matchstick.h"

void fill_limit_game_board(int lines, char **game_board)
{
    for (int i = 0; i < (lines + 2); i++) {
        game_board[i][0] = '*';
        game_board[i] = fill_end_line_star(lines, game_board[i]);
    }
    game_board[0] = fill_star_line(lines, game_board[0]);
    game_board[lines + 1] = fill_star_line(lines, game_board[lines + 1]);
}

char *fill_end_line_star(int lines, char *str)
{
    int count = 1;

    while (count < (max_line_size(lines) - 1)) {
        str[count] = ' ';
        count++;
    }
    str[count] = '*';
    return (str);
}

char *fill_star_line(int lines, char *str)
{
    for (int i = 0; i < max_line_size(lines); i++) {
        str[i] = '*';
    }
    return (str);
}

char **init_game_board(int lines)
{
    char **game_board = malloc(sizeof(char *) * (lines + 3));

    if (game_board == NULL)
        return (NULL);

    game_board[lines + 2] = NULL;
    for (int i = 0; i < (lines + 2); i++) {
        game_board[i] = malloc(sizeof(char) * (max_line_size(lines) + 1));
        if (game_board[i] == NULL)
            return (NULL);
        game_board[i][max_line_size(lines)] = '\0';
    }
    return (game_board);
}

int max_line_size(int lines)
{
    int u_zero = 1;
    int common_difference = 2;
    int result = 0;

    result = u_zero + (lines * common_difference);
    return (result);
}