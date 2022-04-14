CC		  = gcc
MINILIBX	= minilibx/libmlx.a
LFLAGS	  = -framework OpenGL -framework AppKit -L./minilibx -lmlx
CFLAGS	  = -I./include -I./ft_printf -I./minilibx
NAME		= fdf
SRC_DIR	 = src
#BSRCS	  = $(wildcard $(SRC_DIR)/bonus/*_bonus.c)
#BOBJS	  = $(BSRCS:.c=.o)
#MSRCS	  = $(wildcard $(SRC_DIR)/mandatory/*.c)
#MOBJS	  = $(MSRCS:.c=.o)
SRCS		= $(wildcard $(SRC_DIR)/*.c)
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MINILIBX) $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(NAME)
#gcc main.c  -framework OpenGL -framework AppKit -L./minilibx -lmlx 
run: all
	./$(NAME) maps/map2.ber
re: fclean all
clean:
	rm -rf $(OBJS)
	rm -rf $(MOBJS)
	rm -rf $(BOBJS)
	rm -rf log.txt
bonus: OBJS += $(BOBJS)
bonus: $(BOBJS) $(NAME)
fclean: clean
	rm -rf $(NAME)
	@-make clean -C minilibx
.PHONY: clean run fclean re all testm testb bonus norm