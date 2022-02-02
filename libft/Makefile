# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 17:58:34 by fcil              #+#    #+#              #
#    Updated: 2022/02/02 16:55:20 by fcil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = clang
FLAGS = -Wall -Wextra -Werror
SRC=$(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
		ar -rc $(NAME) $(OBJ)

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

main: main.c $(NAME)
	$(CC) $(FLAGS) main.c $(NAME) -o main
	./main


# NAME = libft.a
# CC = clang
# FLAGS = -Wall -Wextra -Werror
# SOURCE = ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
# 			ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
# 			ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c \
# 			ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c \
# 			ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
# 			ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c  \
# 			ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c
# OBJ = $(SOURCE:.c=.o)
# BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c \
# 			ft_lstlast.c ft_lstdelone.c ft_lstclear.c
# B_OBJ = $(BONUS:.c=.o)

# %.o: %.c
# 	$(CC) $(FLAGS) -c $< -o $@

# all: $(NAME)

# $(NAME): $(OBJ)
# 	ar -rc $(NAME) $(OBJ)

# bonus: $(B_OBJ)
# 	ar -rc $(NAME) $(B_OBJ)

# clean:
# 	rm -f $(OBJ) $(B_OBJ)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re main bonus

# main: main.c $(OBJ) $(NAME)
# 	$(CC) -lbsd $(FLAGS) main.c $(NAME) -o main
# 	./main