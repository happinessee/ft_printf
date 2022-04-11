NAME=libftprintf.a

CC= cc
CFLAGS= -Wall -Wextra -Werror
ARFLAGS= ar rcs

SRCS= 	ft_printf.c /
		ft_printf_utils.c /
		ft_decimal.c /
		ft_string.c /
		ft_pointer.c /
		ft_hexa.c /


INCS=	ft_printf.h

OBJS= $(SRCS:.c=.o)

%.o = %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I .

$(NAME) = $(OBJS)
	$(ARFLAGS) $@ $^

all : $(NAME)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : $(NAME)

.PHONY : all, clean, fclean, re, bonus
