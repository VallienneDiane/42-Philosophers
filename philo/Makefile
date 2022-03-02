# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 16:44:45 by dvallien          #+#    #+#              #
#    Updated: 2022/02/24 16:26:21 by dvallien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

LST_INCS := philo.h

LST_SRCS := main.c				\
			ft_parsing.c		\
			ft_utils.c			\
			ft_init_tab_philo.c	\
			ft_create_thread.c	\
			ft_actions.c		\
			ft_start_time.c		\
			ft_mutex_lock.c		\

LST_OBJS := $(LST_SRCS:.c=.o)

CC := gcc

CFLAGS := -g -Wall -Wextra -Werror

RM := rm -rf

DIR_SRCS := srcs
DIR_OBJS := .objects
DIR_INCS := includes

SRCS := $(addprefix $(DIR_SRCS)/, $(LST_SRCS))
OBJS := $(addprefix $(DIR_OBJS)/, $(LST_OBJS))
INCS := $(addprefix $(DIR_INCS)/, $(LST_INCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(DIR_INCS)
	mkdir -p $(DIR_OBJS)
	$(CC) $(CFLAGS) -I$(DIR_INCS) -c $< -o $@

clean:
	$(RM) $(DIR_OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re