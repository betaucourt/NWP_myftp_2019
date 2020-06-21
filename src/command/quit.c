/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "redirect.h"
#include "socket.h"

void quit(char **cmd, int ac, int fd, client_data *data)
{
    cmd = cmd;
    ac = ac;
    dprintf(fd, "221\r\n");
    data->active = 0;
    close(fd);
}
