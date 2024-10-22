SRCS += main.c 		\
		operations/rotate.c 			\
		operations/push.c 				\
		operations/reverse_rotate.c 	\
		operations/swap.c 				\
		sorters/test_sort.c				\
		sorters/steps.c					\
		sorters/sort_utils.c			\
		sorters/radix_sort.c			


OBJS := $(SRCS:.c=.o)

OBJS := $(addprefix build/, $(OBJS))

SRCS := $(addprefix src/, $(SRCS))

NAME = push_swap

CFLAGS += -Wall -Wextra -Werror -Iinclude -Ilibft/include -g

all: $(NAME) libft

libft: 
	$(MAKE) -C libft 

$(NAME): libft $(OBJS) include/*
	cc $(CFLAGS) $(OBJS) -Llibft -lft -o $@

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C libft fclean

re: fclean all libft

.PHONY: all libft clean fclean re