/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "redirect.h"
#include "socket.h"

void user(char **cmd, int ac, int fd, client_data *data)
{
    ac = ac;
    if (cmd[1] && data->user.name == NULL) {
        dprintf(fd, "331\r\n");
        data->user.name = strdup(cmd[1]);
        return;
    } else {
        dprintf(fd, "530\r\n");
        data->user.name = NULL;
        return;
    }
    dprintf(fd, "530\r\n");
}
