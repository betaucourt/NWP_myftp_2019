/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "socket.h"
#include "redirect.h"

int main(int ac, char **av)
{
    if (ac != 3)
        return 84;
    s_socket socket;
    basic_data *basic = malloc(sizeof(basic_data));

    init_struct(&socket, av[1], basic, av[2]);
    socket_loop(&socket, basic->data, basic);
}
