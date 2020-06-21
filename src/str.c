/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "redirect.h"
#include "socket.h"
#include "include.h"

char **split_arg(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **to_ret = malloc(sizeof(char *) * (count_word(str) + 2));

    to_ret[j] = strdup(&str[i]);
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            i++;
            to_ret[j][k] = '\0';
            j++;
            k = 0;
            to_ret[j] = strdup(&str[i]);
            to_ret[j + 1] = NULL;
        }
        if (str[i] == '\0')
            break;
        k++;
        i++;
    }
    return (to_ret[j + 1] = NULL, to_ret);
}

int count_word(char *str)
{
    int i = 0;
    int to_ret = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            to_ret++;
        i++;
    }
    return to_ret;
}
