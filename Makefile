# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 11:21:29 by erigonza          #+#    #+#              #
#    Updated: 2024/05/19 18:32:20 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLEAR_SCREEN = \x1b[1J \x1b[H

SRCS = push_swap.c errors.c utils.c fast_sort.c algorithm.c \
			target_cost_dir.c utils_target_cost_dir.c utils_algorithm.c \
			swap.c push.c rotate.c reverse_rotate.c \
			lst_utils1.c lst_utils2.c
DIR_SRC = ./src
DIR_OBJ = $(DIR_SRC)/obj
OBJS = $(addprefix $(DIR_OBJ)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(DIR_OBJ)/, $(SRCS:.c=.d))
NAME	= push_swap

SRCS_B = push_swap_bonus.c utils_push_swap_bonus.c \
			errors_bonus.c lst_utils1_bonus.c lst_utils2_bonus.c \
			utils_1_bonus.c utils_2_bonus.c \
			swap_bonus.c push_bonus.c rotate_bonus.c reverse_rotate_bonus.c
DIR_OBJ_B = $(DIR_SRC)/obj
OBJS_B = $(addprefix $(DIR_OBJ_B)/, $(SRCS_B:.c=.o))
DEPS_B = $(addprefix $(DIR_OBJ_B)/, $(SRCS_B:.c=.d))
NAME_B = checker

LIB		= src/libft/libft.a

AR		= ar rcs

RM		 = rm -fr

CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=address

CC = cc

all:		libft ${NAME}

libft: 
				@make -C src/libft
				@mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o:		$(DIR_SRC)/%.c Makefile
				@printf "\033[0;33m\r🔨 $< ✅ \033[0m"
				@$(CC) -MMD $(FLAGS)  -c $< -o $@ $(INCLUDES)

${NAME}:	${OBJS} ./inc/push_swap.h
				@${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}
				clear

bonus: libft ${NAME_B}

${NAME_B}:	${OBJS_B} ./inc/push_swap_bonus.h
				@printf "\033[0;33m\r🔨 BONUS $< ✅ \033[0m"
				@${CC} ${CFLAGS} ${OBJS_B} ${LIB} -o ${NAME_B}
				clear

clean:
				@make clean -C src/libft
				@${RM} ${OBJS} ${DEPS} ${OBJS_B} ${DEPS_B}
				clear

fclean:		clean
				@make fclean -C src/libft 
				@${RM} ${NAME} ${NAME_B} ${DIR_OBJ} ${DIR_OBJ_B}
				clear

re:			fclean all

-include ${DEPS} ${DEPS_B}

.PHONY:		clean fclean re all libft bonus
.SILENT:
