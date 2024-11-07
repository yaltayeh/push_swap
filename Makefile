# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 21:16:25 by yaltayeh          #+#    #+#              #
#    Updated: 2024/11/07 11:56:33 by yaltayeh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS += -Wall -Wextra -Werror -g
CFLAGS += -Iinclude -Ilibft/include
FTCLAGS = -Llibft -lft

SRCS += utils.c							\
		steps.c							\
		operations/rotate.c 			\
		operations/push.c 				\
		operations/reverse_rotate.c 	\
		operations/swap.c 				\
		merge_sort/merge_sort.c			\
		merge_sort/merge_2_a.c			\
		merge_sort/merge_2_b.c			\
		merge_sort/get_block_size.c		\
		radix_sort/radix_sort.c			\

MAIN_SRC = src/main.c
ANALYZER_SRC = src/analyzer.c
CHECKER_SRC = src/checker.c

OBJS := $(SRCS:.c=.o)

OBJS := $(addprefix build/, $(OBJS))

SRCS := $(addprefix src/, $(SRCS))

CHECKER =
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	CHECKER = checker_linux
else ifeq ($(UNAME_S), Darwin)
	CHECKER = checker_Mac
endif
NUMBER = 100
ARGS := $(shell python3 rangen.py $(NUMBER))

VISUALIZER_PATH = ../push_swap_visualizer/build/bin/visualizer

all: $(NAME) libft

libft:
	$(MAKE) -C libft 

$(NAME): $(OBJS) $(MAIN_SRC:.c=.o) | libft
	cc $(CFLAGS) $^ $(FTCLAGS) -o $@

checker: $(OBJS) $(ANALYZER_SRC:.c=.o) | libft
	cc $(CFLAGS) $^ $(FTCLAGS) -o $@

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	cc $(CFLAGS) $(INCLUDE) -c $< -o $@

checker_Mac:
	wget https://cdn.intra.42.fr/document/document/28301/checker_Mac
	chmod +x checker_Mac

checker_linux:
	wget https://cdn.intra.42.fr/document/document/28302/checker_linux
	chmod +x checker_linux

test: $(NAME) $(CHECKER)
	./$(NAME) $(ARGS) > steps
	@printf "\nres:    " 
	@cat steps | ./$(CHECKER) $(ARGS)
	@printf "steps: "
	@cat steps | wc -l

ifeq ($(UNAME_S), Linux) 
visualizer: $(NAME)
	./$(VISUALIZER_PATH)
endif

clean:
	rm -rf $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C libft fclean

re: fclean all libft

.PHONY: all libft clean fclean test re