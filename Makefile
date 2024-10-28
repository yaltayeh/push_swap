SRCS += main.c 		\
		utils.c						\
		operations/rotate.c 		\
		operations/push.c 			\
		operations/reverse_rotate.c \
		operations/swap.c 			\
		sorters/test_sort.c			\
		sorters/test2_sort.c		\
		sorters/steps.c				\
		sorters/sort_utils.c		\
		sorters/radix_sort.c		\

OBJS := $(SRCS:.c=.o)

OBJS := $(addprefix build/, $(OBJS))

SRCS := $(addprefix src/, $(SRCS))

NAME = push_swap
CFLAGS += -Wall -Wextra -Werror 
INCLUDE = -Iinclude -Ilibft/include
FTCLAGS = -Llibft -lft

# genrate test case and select checker
UNAME_S := $(shell uname -s)
NUMBER = 100
CHECKER = 
ifeq ($(UNAME_S), Linux)
	CHECKER = checker_linux
else ifeq ($(UNAME_S), Darwin)
	CHECKER = checker_Mac
endif
ARGS = $(shell python3 rangen.py $(NUMBER))

all: $(NAME) libft

libft: 
	$(MAKE) -C libft 

$(NAME): libft $(OBJS) include/*
	cc $(CFLAGS) $(OBJS) $(FTCLAGS) -o $@

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	cc $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C libft fclean

test: $(NAME) $(CHECKER)
	./$(NAME) $(ARGS) | ./$(CHECKER) $(ARGS)

re: fclean all libft

.PHONY: all libft clean fclean test re