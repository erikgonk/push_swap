# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 11:21:29 by erigonza          #+#    #+#              #
#    Updated: 2024/04/15 18:21:37 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW = \033[0;93m
WHITE = \033[1m
CLEAR_SCREEN = \x1b[1J \x1b[H

#-----------------------------------VARIABLES----------------------------------#

NAME = push_swap

LIBFT = src/libft/
LIBFT_A = $(addprefix $(LIBFT), libft.a)

SRC_NAMES = main.c errors.c utils.c fast_sort.c algorithm.c \
			swap.c push.c rotate.c reverse_rotate.c \
			lst_utils1.c lst_utils2.c
SRCS = $(addprefix src/, $(SRC_NAMES))
OBJS = $(SRCS:%.c=%.o)
DEPS = $(SRCS:%.c=%.d)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

LDFLAGS = -L$(LIBFT) 

RM = rm -fr

#------------------------------------EXECUTE-----------------------------------#

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS)  -Iinc -I$(LIBFT) $(LDFLAGS) $(LIBFT_A) $(SRCS) -o $(NAME)

$(OBJS): %.o: %.c Makefile $(LIBFT_A)
	$(CC) $(CFLAGS) -Iinc -I$(LIBFT) -MMD -c -o $@ $<
	echo -n "$(CLEAR_SCREEN)"

libft:
	make -C $(LIBFT) --no-print-directory

#-------------------------------------CLEAN------------------------------------#

clean:
	$(RM) $(OBJS) $(DEPS) --no-print-directory
	make clean -C $(LIBFT) --no-print-directory
	rm -fr push_swap.dSYM --no-print-directory

fclean: clean
	$(RM) $(NAME) --no-print-directory
	make fclean -C $(LIBFT) --no-print-directory

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re libft
.SILENT: