# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 11:59:00 by cabo-ram          #+#    #+#              #
#    Updated: 2024/12/24 17:57:55 by cabo-ram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

SRC = main.c utils.c
SRC_BONUS = main_bonus.c utils.c utils_bonus.c \

OBJS = $(SRC:.c=.o)
OBJSBONUS = $(SRC_BONUS:.c=.o)

HEADER = ../includes
LIBFT = ../libraries/libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(HEADER)/includes -g

RM = rm -rf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT) -lft

bonus: $(OBJSBONUS)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJSBONUS) -L$(LIBFT) -lft
#	@make OBJS="$(OBJSBONUS)" --no-print-directory

clean:
	$(RM) $(OBJS) $(OBJSBONUS)
	@make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus