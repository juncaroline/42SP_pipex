# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 11:59:00 by cabo-ram          #+#    #+#              #
#    Updated: 2024/12/20 16:58:39 by cabo-ram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = main.c utils.c \

OBJS =$(SRC:.c=.o)
HEADER = ../includes
LIBFT = ../libraries/libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(HEADER)/includes -g

RM = rm -rf

all: $(NAME)

%.o: %.C
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT) -lft

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re