# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 21:16:25 by yaltayeh          #+#    #+#              #
#    Updated: 2024/11/28 08:19:38 by yaltayeh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC		= cc
CFLAGS += -Wall -Wextra -Werror -g
CFLAGS += -Iinclude -Ilibft/include
LDFLAGS = -Llibft -lft

SRCS += main.c							\
		utils.c							\
		step/step.c						\
		step/step_utils.c				\
		step/steps_reducer.c			\
		operations/rotate.c 			\
		operations/push.c 				\
		operations/reverse_rotate.c 	\
		operations/swap.c 				\
		merge_sort/merge_sort.c			\
		merge_sort/merge_2_a.c			\
		merge_sort/merge_2_b.c			\
		merge_sort/get_block_size.c		\

SRCS := $(addprefix src/, $(SRCS))
OBJS := $(SRCS:src/%.c=build/%.o)


# Set colors variables
RESET	= \033[0;39m
RED		= \033[0;91m
GREEN	= \033[0;92m
MAGENTA	= \033[0;95m
YELLOW	= \033[0;93m

all: $(NAME)

libft:
	@git submodule update --init
	@$(MAKE) -C libft --no-print-directory

$(NAME): $(OBJS) | libft
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@ \
		&& echo "$(GREEN)Linking objects and create \"$@\"$(RESET)"\
		|| echo "$(RED)Error in try linking $(OBJS)$(RESET)"

build/%.o: src/%.c | libft
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ \
		&& echo "$(GREEN)Build $@ object from $< $(RESET)"\
		|| echo "$(RED)Error in try build $< $(RESET)"

clean:
	@rm -rf $(OBJS) \
		&& echo "$(YELLOW)PUSH_SWAP: remove all object files$(RESET)"\
		|| echo "$(RED)PUSH_SWAP: Can't remove object files$(RESET)"
	@$(MAKE) clean -C libft --no-print-directory

fclean:
	@rm -rf $(OBJS) \
		&& echo "$(YELLOW)PUSH_SWAP: Remove all object files$(RESET)"\
		|| echo "$(RED)PUSH_SWAP: Can't remove object files$(RESET)"
	@rm -rf $(NAME) \
		&& echo "$(YELLOW)PUSH_SWAP: Remove $(NAME)$(RESET)"\
		|| echo "$(RED)PUSH_SWAP: Can't remove $(NAME)$(RESET)"
	@$(MAKE) fclean -C libft --no-print-directory

re: fclean all libft

CHECKER =
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	CHECKER = checker_linux
else ifeq ($(UNAME_S), Darwin)
	CHECKER = checker_Mac
endif
NUMBER ?= 100
ifneq ($(CHECKER), )
ARGS := $(shell python3 rangen.py $(NUMBER))
test: $(NAME) $(CHECKER) rangen.py
	./$(NAME) $(ARGS) > steps
	@printf "\nres:    " 
	@cat steps | ./$(CHECKER) $(ARGS)
	@printf "steps: "
	@cat steps | wc -l
endif

VISUALIZER_PATH = ../push_swap_visualizer/build/bin/visualizer

ifeq ($(UNAME_S), Linux) 
visualizer: $(NAME)
	./$(VISUALIZER_PATH)
endif

rangen.py:
	wget https://raw.githubusercontent.com/yaltayeh/push_swap/refs/heads/main/rangen.py

checker_Mac:
	wget https://cdn.intra.42.fr/document/document/28301/checker_Mac
	chmod +x checker_Mac

checker_linux:
	wget https://cdn.intra.42.fr/document/document/28302/checker_linux
	chmod +x checker_linux

.PHONY: all libft clean fclean test re
