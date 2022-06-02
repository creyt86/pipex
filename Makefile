# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 10:54:18 by creyt             #+#    #+#              #
#    Updated: 2022/06/02 10:57:27 by creyt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
HEAD = pipex.h
CC = gcc
CFLAGS = -Werror -Wextra -Wall -g# -fsanitize=address
OBJS = ${SRCS:.c=.o}
SRCS =	pipex.c
FT_PRINTF_PATH = ft_printf/

RM = rm -f

all: ${NAME}

$(NAME):	$(OBJS)
		@$(MAKE) -C $(FT_PRINTF_PATH)
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME) $(LIB)

%o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	${RM} ${OBJS}
	@$(MAKE) -C $(FT_PRINTF_PATH) clean

fclean: clean
	${RM} ${NAME}
	@$(MAKE) -C $(FT_PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
