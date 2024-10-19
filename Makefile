SRCS +=	push_swap.c	main.c


OBJS := $(SRCS:.c=.o)

OBJS := $(addprefix build/, $(OBJS))

SRCS := $(addprefix src/, $(SRCS))

NAME = push_swap

CFLAGS += -Iinclude -Ilibft/include

all: $(NAME) libft

libft: 
	$(MAKE) -C libft 

$(NAME): $(OBJS) include/*
	cc $(CFLAGS) $(OBJS) -Llibft -lft -o $@

build:
	mkdir -p $@

build/%.o: src/%.c | build
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all libft