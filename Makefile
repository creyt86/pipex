# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 10:54:18 by creyt             #+#    #+#              #
#    Updated: 2022/06/16 16:14:17 by creyt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_B = pipex_bonus
HEAD = pipex.h
CC = gcc
CFLAGS = -Werror -Wextra -Wall -g #-fsanitize=address

OBJS = ${SRCS:.c=.o}
SRCS =	mandatory/pipex.c \
		mandatory/pipex_utils.c \
		utils_libft/ft_putstr_fd.c \
		utils_libft/ft_split.c \
		utils_libft/ft_strjoin.c \
		utils_libft/ft_strlen.c \
		utils_libft/ft_strnstr.c

OBJS_B	= ${SRCS_B:.c=.o}
SRCS_B = bonus/pipex_utils_bonus.c \
		mandatory/pipex_utils.c \
		bonus/pipex_bonus.c \
		utils_libft/ft_putstr_fd.c \
		utils_libft/ft_split.c \
		utils_libft/ft_strjoin.c \
		utils_libft/ft_strlen.c \
		utils_libft/ft_strncmp.c \
		utils_libft/ft_strnstr.c

RM = rm -f

all: ${NAME}

$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
		@echo "\033[34m----Compiling lib----"
		@$(CC) ${OBJS}
		@printf "$(GREEN)🚰 Creating $(NAME)$(RESET)\n"
		@sleep 0.5
		@echo "\033[35mPipex Compiled! ᕦ(\033[31m♥\033[35m_\033[31m♥\033[35m)ᕤ\n"

%o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:		${NAME_B}

${NAME_B}:	${OBJS_B}
			$(CC) $(OBJS_B) $(CFLAGS) -o $(NAME_B)
	 		@printf "$(GREEN)🚰 Creating $(NAME_B)$(RESET)\n"
			@sleep 0.5
			@echo "\033[34m----Compiling lib----"
			@echo "\033[35mPipex Bonus Compiled! ᕦ(\033[31m♥\033[35m_\033[31m♥\033[35m)ᕤ\n"


clean:
	${RM} ${OBJS} ${OBJS_B}
	@printf "$(YELLOW)🧽 Clean $(NAME) $(NAME_B)$(RESET)\n"
	@sleep 0.5


fclean: clean
	${RM} ${NAME}
	${RM} ${NAME_B}
	@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"
	@printf "\r$(PURP)🗑  Remove $(NAME)$(NAME_B)$(RESET)\n"
	@sleep 0.5

re: fclean all
re_bonus : fclean bonus

.PHONY: all clean fclean re re_bonus bonus
