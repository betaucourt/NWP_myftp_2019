/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "redirect.h"
#include "socket.h"
#include "include.h"
#include <sys/types.h>
#include <dirent.h>

char *handle_pwd(char *path)
{
    if (opendir(path) == NULL) {
        exit(84);
    }
    return strdup(path);
}

void init_struct(s_socket *sock, char *port, basic_data *basic, char *pwd)
{
    uint16_t servPort = atoi(port);
    char *tmp = handle_pwd(pwd);

    if (tmp == NULL)
        basic->pwd = NULL;
    else
        basic->pwd = strdup(tmp);
    sock->fd = socket(PF_INET, SOCK_STREAM, 0);
    sock->addr.sin_family = AF_INET;
    sock->addr.sin_port = htons(servPort);
    sock->addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(sock->fd, (struct sockaddr *) &sock->addr, sizeof(sock->addr));
    listen(sock->fd, 128);
}

struct s_redirect init_redirect(void)
{
    struct s_redirect to_ret;

    to_ret.func[3] = &cdup;
    to_ret.func[2] = &cwd;
    to_ret.func[5] = &dele;
    to_ret.func[9] = &help;
    to_ret.func[13] = &list;
    to_ret.func[10] = &noop;
    to_ret.func[1] = &pass;
    to_ret.func[7] = &pasv;
    to_ret.func[8] = &port;
    to_ret.func[6] = &pwd;
    to_ret.func[4] = &quit;
    to_ret.func[11] = &retr;
    to_ret.func[12] = &stor;
    to_ret.func[0] = &user;
    to_ret.func[14] = NULL;
    return to_ret;
}
