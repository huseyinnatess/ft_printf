NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = 	ft_itoa.c \
		ft_printf_utlis.c \
		ft_printf.c \

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar -rc $(NAME) $(OBJS) 

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re