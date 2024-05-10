# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 11:21:29 by erigonza          #+#    #+#              #
#    Updated: 2024/05/10 13:24:35 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLEAR_SCREEN = \x1b[1J \x1b[H

SRCS = main.c errors.c utils.c fast_sort.c algorithm.c \
			target_cost_dir.c utils_target_cost_dir.c utils_algorithm.c \
			swap.c push.c rotate.c reverse_rotate.c \
			lst_utils1.c lst_utils2.c

OBJS	= ${SRCS:.c=.o}

DEPS	= ${SRCS:.c=.d}

NAME	= push_swap

LIB		= src/libft/libft.a

AR		= ar rcs

RM		 = rm -f

CC		 = cc

CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=address

all:		libft ${NAME}

libft: 
			make -C src/libft

%.o:		src/%.c Makefile
				${CC} ${CFLAGS} -c $< -MMD

${NAME}:	${OBJS} ./inc/push_swap.h
				${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}
				echo -n "$(CLEAR_SCREEN)"

clean:
				make clean -C src/libft
				${RM} ${OBJS} ${DEPS} ${BDEPS}
				echo -n "$(CLEAR_SCREEN)"

fclean:		clean
				make fclean -C src/libft 
				${RM} ${NAME}
				echo -n "$(CLEAR_SCREEN)"

re:			fclean all

-include ${DEPS}

.PHONY:		clean fclean re all libft
.SILENT:
