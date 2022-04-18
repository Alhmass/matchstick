/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include "matchstick_struct.h"
#include "lib.h"
#include <stdlib.h>
#include <stdio.h>

char **init_game_board(int lines);
int max_line_size(int lines);
int verif_game(int lines, int max_matches);
void fill_limit_game_board(int lines, char **game_board);
char *fill_star_line(int lines, char *str);
void fill_matchstick(int lines, char **game_board);
char *fill_end_line_star(int lines, char *str);
void delete_stick(int actual_player, char **game_board, int line, int nb_stick);
game_data *init_struct(char **argv);
int matchstick(game_data *game);
char *get_player_entry();
int player_turn(game_data *game);
int verif_entry(char *entry);
int matches_entry(int line, game_data *game);
int line_entry(game_data *game);
int stick_len(char *line);
int verif_matches_line(char *matches_entry, int line, game_data *game);
void print_remove_message(int actual_player, int line, int nb_stick);
int total_stick_len(char **game_board);
int nb_taken_matches(game_data *game);
void ai_turn(game_data *game);
int line_enough_matches(int nb_taken, char **game_board);
void verif_game_status(game_data *game, int actual_player);
void end_message(int actual_player, game_data *game);
int verif_input(const char *input);
int verif_matches_input(char *matches_entry, int line, game_data *game);

#endif