

NAME =		myftp

RM = 		rm -f

CC = 		gcc

CFLAGS = 	-Wall -Wextra -Iinclude -g

DIR = src/

SOCKET = socket/

COMMAND = command/


SRCS =	$(DIR)main.c	\
				$(DIR)init.c	\
				$(DIR)realmain.c	\
				$(DIR)newconnection.c	\
				$(DIR)str.c		\
				$(DIR)$(COMMAND)cdup.c	\
				$(DIR)$(COMMAND)cwd.c	\
				$(DIR)$(COMMAND)dele.c	\
				$(DIR)$(COMMAND)help.c	\
				$(DIR)$(COMMAND)list.c	\
				$(DIR)$(COMMAND)noop.c	\
				$(DIR)$(COMMAND)pass.c	\
				$(DIR)$(COMMAND)pasv.c	\
				$(DIR)$(COMMAND)port.c	\
				$(DIR)$(COMMAND)pwd.c	\
				$(DIR)$(COMMAND)quit.c	\
				$(DIR)$(COMMAND)retr.c	\
				$(DIR)$(COMMAND)stor.c	\
				$(DIR)$(COMMAND)user.c	\
				$(DIR)$(COMMAND)verification.c

all: $(NAME)


OBJS = 		$(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all
