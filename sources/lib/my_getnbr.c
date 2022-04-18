/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** Write a function that returns a number, sent to the function as a string.
*/

#include "../../includes/lib.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    while (str[i] != '\0') {
        if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
            neg = -1;
        else if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = (nb + (str[i] - 48));
        }
        else if (nb > 1 && (!(str[i] >= '0' && str[i] <= '9'))) {
            nb = nb * neg;
            return (nb);
        }
        i++;
    }
    nb = nb * neg;
    return (nb);
}
