/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "redirect.h"
#include "socket.h"

void bad_command(client_data *client, int fd)
{
    if (client->user.logged == -1)
        dprintf(fd, "530\r\n");
    else
        dprintf(fd, "500\r\n");
}

int verification(client_data *client, int fd)
{
    if (client->user.logged == -1) {
        write(fd, "530\r\n", 4);
        return -1;
    }
    return 1;
}

int cmd_length(char **cmd)
{
    int i = 0;

    while (cmd[i] != NULL) {
        i++;
    }
    return i;
}
