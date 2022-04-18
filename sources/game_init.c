/*
** EPITECH PROJECT, 2021
** game_init.
** File description:
** game_init
*/

#include "matchstick.h"

game_data *init_struct(char **argv)
{
    game_data *data = malloc(sizeof(game_data));

    if (data == NULL)
        return (NULL);
    else if (verif_input(argv[0]) == 84)
        return (NULL);
    else if (verif_input(argv[1]) == 84)
        return (NULL);
    data->nb_lines = my_getnbr(argv[0]);
    data->max_matches = my_getnbr(argv[1]);
    data->game_status = 0;
    if (verif_game(data->nb_lines, data->max_matches) == 84)
        return (NULL);
    data->game_board = init_game_board(data->nb_lines);
    if (data->game_board == NULL)
        return (NULL);
    fill_limit_game_board(data->nb_lines, data->game_board);
    fill_matchstick(data->nb_lines, data->game_board);
    return (data);
}

int verif_input(const char *input)
{
    char valid_input[] = "0123456789";

    for (int i = 0; input[i] != '\0'; i++) {
        if (my_strchr(valid_input, input[i]) == 1)
            return (84);
    }
    return (0);
}

int verif_game(int lines, int max_matches)
{
    if (lines < 1 || lines > 100)
        return (84);
    else if (max_matches <= 0)
        return (84);
    else
        return (0);
}

void fill_matchstick(int lines, char **game_board)
{
    int max_line = max_line_size(lines) - 1;
    int start_line = 1;

    for (int i = lines; i > 0; i--) {
        for (int k = start_line; k < max_line; k++) {
            game_board[i][k] = '|';
        }
        start_line++;
        max_line--;
    }
}
