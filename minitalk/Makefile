# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 13:51:48 by fcil              #+#    #+#              #
#    Updated: 2022/03/15 13:57:50 by fcil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	:=
SERVER	:= server
CLIENT	:= client

LIBFT_A		:= ./libft/libft.a
CLIENT_SRC	:= client.c
SERVER_SRC	:= server.c

CFLAGS		:= -Wall -Werror -Wextra

$(NAME): all

all: $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT_A)
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIBFT_A) -o $(CLIENT)

$(SERVER): $(LIBFT_A)
	$(CC) $(CFLAGS) $(SERVER_SRC) $(LIBFT_A) -o $(SERVER)

$(LIBFT_A):
	@make -C libft

clean:
	@make -C libft clean
	rm -rf *.o

fclean:
	@make -C libft fclean
	rm -rf *.o $(SERVER) $(CLIENT)

re:	fclean all

.PHONY: all clean fclean re