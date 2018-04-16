# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 18:16:29 by sklepper          #+#    #+#              #
#    Updated: 2018/04/16 16:00:35 by sklepper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_C = ft_bzero.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_power.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putendl.c \
		ft_putnbr_fd.c \
		ft_putnbr.c \
		ft_putstr_fd.c \
		ft_putstr.c \
		ft_puttab.c \
		ft_strclr.c \
		ft_strdel.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnew.c \
		ft_strnequ.c \
		ft_strsplit.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_memcmp.c \
		ft_memcmp.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_isalnum.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_min.c \
		ft_strncpy.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstmap.c \
		ft_lstiter.c \
		ft_lstadd.c \
		ft_max.c \
		ft_lstaddend.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstat.c \
		ft_lstrev.c \

SRC_O = $(SRC_C:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRC_C)
	ar rc $(NAME) $(SRC_O)
	ranlib $(NAME)

clean:
	rm -rf $(SRC_O)

fclean: clean
	rm -f $(NAME)

re: fclean all
