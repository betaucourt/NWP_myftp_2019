/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "redirect.h"
#include "socket.h"

void pass(char **cmd, int ac, int fd, client_data *data)
{
    ac = ac;
    if (cmd_length(cmd) <= 2) {
        if (data->user.name && strcasecmp(data->user.name, "Anonymous") == 0) {
            dprintf(fd, "332\r\n");
            data->user.logged = 1;
            return;
        } else {
            dprintf(fd, "530\r\n");
            return;
        }
    } else if (strcmp(cmd[1], "null") == 0) {
        dprintf(fd, "332\r\n");
        return;
    }
    dprintf(fd, "530\r\n");
}
