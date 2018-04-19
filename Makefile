# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/16 18:24:33 by nihuynh           #+#    #+#              #
#    Updated: 2018/04/19 00:12:54 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Config Fillit:
NAME	:=	fillit
SRC		:=	main.c reader.c toolbox.c parse_tools.c display.c
HEAD	:=	fillit.h Libft/libft.h
MAP		:=	./map/.fillit
DEBUG	:=	TRUE
RM		:=	/bin/rm -f
CC		:=	clang
CFLAG	:=	-Werror -Wall -Wextra
DEBUGCC :=	-g -fsanitize=address
# **************************************************************************** #
# directories :
SRCDIR  :=	.
OBJDIR 	:=	./objs
INCDIR  :=	.
LIBDIR	:=	./Libft
# **************************************************************************** #
# Automatic variable :
INCFLAG	:=	-I$(LIBDIR) -I$(INCDIR)
LIBFLAG	:=	-L$(LIBDIR) -lft
OBJ		:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
# **************************************************************************** #
# Target rules :
all: $(NAME)
$(NAME): $(LIBDIR)/libft.a $(OBJ) $(HEAD)
	$(CC) $(CFLAG) -o $@ $(OBJ) $(LIBFLAG) $(INCFLAG)
$(LIBDIR)/libft.a:
	make -C $(LIBDIR)/ fclean && make -C $(LIBDIR)/
$(OBJDIR)/%.o: %.c
	mkdir $(OBJDIR) 2> /dev/null || true
	$(CC) $(CFLAG) $(INCFLAG) -o $@ -c $<
clean:
	$(RM) $(OBJ)
	rmdir $(OBJDIR) 2> /dev/null || true
fclean: clean
	make -C $(LIBDIR)/ fclean
	$(RM) $(NAME)
re: fclean all
debug : clean $(OBJ)
	$(CC) $(CFLAG) $(DEBUGCC) -o $(NAME) $(OBJ) $(LIBFLAG) $(INCFLAG)
.PHONY: all, $(NAME), clean, fclean, re, val
