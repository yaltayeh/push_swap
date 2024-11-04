# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 21:16:25 by yaltayeh          #+#    #+#              #
#    Updated: 2024/11/03 23:47:30 by yaltayeh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS += utils.c						\
		steps.c						\
		operations/rotate.c 		\
		operations/push.c 			\
		operations/reverse_rotate.c \
		operations/swap.c 			\
		get_block_size.c			\
		merge_sort.c				\
		merge_2_a.c					\
		merge_2_b.c					\
	

MAIN_SRC = src/main.c
ANALYZER_SRC = src/analyzer.c
#CHECKER_SRC = 

OBJS := $(SRCS:.c=.o)

OBJS := $(addprefix build/, $(OBJS))

SRCS := $(addprefix src/, $(SRCS))

NAME = push_swap
CFLAGS += -Wall -Wextra -Werror -g
CFLAGS += -Iinclude -Ilibft/include
FTCLAGS = -Llibft -lft

MY_CHECKER = analyzer
UNAME_S := $(shell uname -s)
NUMBER = 100
CHECKER = 
ifeq ($(UNAME_S), Linux)
	CHECKER = checker_linux
else ifeq ($(UNAME_S), Darwin)
	CHECKER = checker_Mac
endif
ARGS := $(shell python3 rangen.py $(NUMBER))


VISUALIZER_PATH = ../push_swap_visualizer/build/bin/visualizer

all: $(NAME) libft

libft:
	$(MAKE) -C libft 

$(NAME): $(OBJS) $(MAIN_SRC:.c=.o) | libft
	cc $(CFLAGS) $^ $(FTCLAGS) -o $@

$(MY_CHECKER): $(OBJS) $(ANALYZER_SRC:.c=.o) | libft include/*
	cc $(CFLAGS) $^ $(FTCLAGS) -o $@

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	cc $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C libft fclean

tmp:
	mkdir tmp

test: $(NAME) $(CHECKER) | tmp
	./$(NAME) $(ARGS) > tmp/steps
	@printf "\nres:    " 
	@cat tmp/steps | ./$(CHECKER) $(ARGS)
	@printf "steps: "
	@cat tmp/steps | wc -l

ifeq ($(UNAME_S), Linux) 
visualizer: $(NAME)
	./$(VISUALIZER_PATH)
endif

re: fclean all libft

.PHONY: all libft clean fclean test re