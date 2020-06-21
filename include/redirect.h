/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#ifndef REDIRECT_H_
#define REDIRECT_H_

#include "socket.h"

struct s_redirect
{
    void (*func[15])(char **cmd, int ac, int fd, client_data *data);
};

void cdup(char **cmd, int ac, int fd, client_data *data);
void cwd(char **cmd, int ac, int fd, client_data *data);
void dele(char **cmd, int ac, int fd, client_data *data);
void help(char **cmd, int ac, int fd, client_data *data);
void list(char **cmd, int ac, int fd, client_data *data);
void noop(char **cmd, int ac, int fd, client_data *data);
void pass(char **cmd, int ac, int fd, client_data *data);
void pasv(char **cmd, int ac, int fd, client_data *data);
void port(char **cmd, int ac, int fd, client_data *data);
void pwd(char **cmd, int ac, int fd, client_data *data);
void quit(char **cmd, int ac, int fd, client_data *data);
void retr(char **cmd, int ac, int fd, client_data *data);
void stor(char **cmd, int ac, int fd, client_data *data);
void user(char **cmd, int ac, int fd, client_data *data);
#endif // REDIRECT_H_
