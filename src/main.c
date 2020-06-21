/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "socket.h"
#include "redirect.h"
#define MAXMSG  512

int choose_cmd(char *to_check)
{
    int i = 0;
    char *serv_cmd[16] = {"USER", "PASS", "CWD", "CDUP", "QUIT", "DELE",
    "PWD", "PASV", "PORT", "HELP", "NOOP", "RETR", "STOR", "LIST", NULL};

    while (serv_cmd[i] != NULL) {
        if (strcmp(serv_cmd[i], to_check) == 0) {
            return i;
        }
        i++;
    }
    return -1;
}

int handle_arg(char **av, int ac, int fd, client_data *data)
{
    int cmd = choose_cmd(av[0]);
    struct s_redirect redir = init_redirect();

    if (cmd == -1) {
        bad_command(data, fd);
    } else {
        if (cmd == 4) {
            quit(av, ac, fd, data);
            return 0;
        } else if (cmd == -1) {
            dprintf(fd, "500\r\n");
        } else {
            redir.func[cmd](av, ac, fd, data);
        }
    }
    return -1;
}

int found_client(int fd, client_data **data)
{
    int i = 0;

    while (data[i] != NULL) {
        if (data[i]->fd == fd) {
            break;
        }
        i++;
    }
    return i;
}

int read_from_client(int filedes, client_data **data)
{
    int ret;
    char buffer[MAXMSG];
    int nbytes = read(filedes, buffer, MAXMSG);
    buffer[nbytes - 2] = '\0';
    char **av = split_arg(buffer);

    ret = handle_arg(av, count_word(buffer) + 1,
    filedes, data[found_client(filedes, data)]);
    if (ret == 0)
        return -1;
    return 1;
}

void socket_loop(s_socket *socket, client_data **data, basic_data *basic)
{
    int sock = socket->fd, new;
    fd_set active_fd_set, read_fd_set;
    struct sockaddr_in clientname;

    FD_ZERO(&active_fd_set);
    FD_SET(sock, &active_fd_set);
    while (1) {
        read_fd_set = active_fd_set;
        select(FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) < 0 ? exit(0) : 1;
        for (int i = 0; i < FD_SETSIZE; i++)
            if (FD_ISSET(i, &read_fd_set))
                if (i == sock) {
                    accept_new_connection(clientname, sock, &new, basic);
                    FD_SET(new, &active_fd_set);
                } else if (read_from_client(i, data) < 0) {
                        close(i);
                        FD_CLR(i, &active_fd_set);
                        break;
                    }
    }
}
