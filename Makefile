CLIENT		= client

SERVER		= server

SRC_CLIENT	= client.c

SRC_SERVER	= server.c

OBJ_SERVER	= $(SRC_SERVER:.c=.o)

OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)

CC		= gcc

CFLAGS		+= -Wall -Wextra -Werror

RM		= rm -f

INCLUDES	= libft/libft.a

all:		$(CLIENT) $(SERVER)

$(SERVER):	$(OBJ_SERVER)
		$(CC) -o $(SERVER) $(OBJ_SERVER) $(INCLUDES)

$(CLIENT):	$(OBJ_CLIENT)
		$(CC) -o $(CLIENT) $(OBJ_CLIENT) $(INCLUDES)

clean:
		$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean:		clean
		$(RM) $(SERVER) $(CLIENT)

re:		fclean all
