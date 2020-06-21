/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#ifndef SOCKET_H_
#define SOCKET_H_

#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "include.h"

enum e_connection_type {
    ACTIVE,
    PASSIVE,
};

typedef struct a_socket s_socket;
typedef struct data_socket s_data_socket;
typedef struct user s_user;
typedef struct client s_client;
typedef union u_port t_port;
typedef struct s_client_data client_data;
typedef struct s_basic_data basic_data;

struct s_basic_data {
    char *pwd;
    int bite;
    client_data *data[128];
};

struct user {
    char *name;
    int logged;
};

union u_port {
    uint16_t full;
    uint8_t byte[2];
};

struct a_socket {
    int fd;
    struct sockaddr_in addr;
    t_port port;
};

struct data_socket {
    s_socket socket;
    enum e_connection_type type;
    int active;
};

struct s_client_data {
    int fd;
    char *pwd;
    char *sin_addr;
    int sin_port;
    s_user user;
    int active;
};

struct client {

    FILE *stream_fd;
    s_socket socket;
    s_data_socket data_socket;
    s_user user;
    size_t message_length;
    char *input;
    char **args;
    char *path;
    char *base_path;
    int active;
};

char *handle_pwd(char *path);
void init_struct(s_socket *sock, char *port, basic_data *basic, char *pwd);
struct s_redirect init_redirect();
int count_word(char *str);
char **split_arg(char *str);
client_data *new_connection(struct sockaddr_in clientname, int fd);
void accept_new_connection(struct sockaddr_in clientname, int sock,
int *new, basic_data *data);
int verification(client_data *client, int fd);
int cmd_length(char **cmd);
void socket_loop(s_socket *socket, client_data **data, basic_data *basic);
void bad_command(client_data *client, int fd);

#endif // SOCKET_H_
