/*
** EPITECH PROJECT, 2021
** matchstick_struct
** File description:
** matchstick_struct
*/

#ifndef MATCHSTICK_STRUCT_H_
#define MATCHSTICK_STRUCT_H_

typedef struct game_data {
    char **game_board;
    int game_status;
    int nb_lines;
    int max_matches;
} game_data;

typedef enum player_e {
    player = 1,
    ai = 2,
} player_e;

#endif /* !MATCHSTICK_STRUCT_H_ */
