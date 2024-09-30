SRCS =	ft_lstnew.c				\
		ft_lstlast.c		ft_lstsize.c 			\
		ft_lstpush_front.c	ft_lstpush_back.c		\
		ft_lstpop_front.c	ft_lstpop_back.c		\
		ft_lstiter.c		ft_lstmap.c				\
		ft_lstdelone.c		ft_lstclear.c			\

SRCS +=	push_swap.c	main.c


OBJS := $(SRCS:.c=.o)

OBJS := $(addprefix build/, $(OBJS))

SRCS := $(addprefix src/, $(SRCS))

NAME = push_swap

CFLAGS += -Iinclude

all: $(NAME)

$(NAME): $(OBJS) include/*
	cc $(CFLAGS) $(OBJS) -o $@

build:
	mkdir -p $@

build/%.o: src/%.c | build
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all