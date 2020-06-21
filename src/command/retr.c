/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "redirect.h"
#include "socket.h"

void retr(char **cmd, int ac, int fd, client_data *data)
{
    cmd = cmd;
    ac = ac;
    if (verification(data, fd) == -1) {
        return;
    }
    dprintf(fd, "425\r\n");
}
