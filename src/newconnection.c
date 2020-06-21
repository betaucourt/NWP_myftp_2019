/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "redirect.h"
#include "socket.h"
#include "include.h"

client_data *new_connection(struct sockaddr_in clientname, int fd)
{
    client_data *to_ret = malloc(sizeof(client_data));

    to_ret->sin_addr = inet_ntoa(clientname.sin_addr);
    to_ret->sin_port = ntohs(clientname.sin_port);
    to_ret->fd = fd;
    to_ret->user.name = NULL;
    to_ret->user.logged = -1;
    to_ret->active = 1;
    to_ret->pwd = strdup("/");
    return to_ret;
}

int find_free(client_data **data)
{
    int i = 0;

    while (data[i] != NULL && data[i]->active != 0)
        i++;
    return i;
}

void accept_new_connection(struct sockaddr_in clientname,
    int sock, int *new, basic_data *data)
{
    size_t size;
    int fd = (*new);
    int free = find_free(data->data);

    size = sizeof(clientname);
    fd = accept(sock, (struct sockaddr *)&clientname, (socklen_t *)&size);
    if (fd < 0) {
        exit(0);
    }
    data->data[free] = new_connection(clientname, fd);
    dprintf(fd, "220\r\n");
    (*new) = fd;
}
