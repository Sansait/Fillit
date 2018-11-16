# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/16 18:24:33 by nihuynh           #+#    #+#              #
#    Updated: 2018/11/16 17:56:21 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fillit
SRC		:=	main.c utils_tools.c display.c \
			parser.c  parse_tools.c \
			solver.c solver_tools.c
HEAD	:=	fillit.h
DEBUG	:=	TRUE
RM		:=	/bin/rm -f
CC		:=	clang
CFLAG	:=	-Werror -Wall -Wextra
DEBUGCC :=	-g -fsanitize=address
# **************************************************************************** #
# directories :
SRCDIR  :=	./srcs
OBJDIR 	:=	./objs
INCDIR  :=	./includes
LIBDIR	:=	./Libft
# **************************************************************************** #
# Automatic variable :
INCFLAG	:=	-I$(LIBDIR) -I$(INCDIR)
LIBFLAG	:=	$(LIBDIR)/libft.a
OBJ		:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
HEADS	:=	$(addprefix $(INCDIR)/, $(HEAD))
# **************************************************************************** #
# Target rules :
all: $(NAME)
$(NAME): $(LIBDIR)/libft.a $(OBJ) $(HEADS)
	$(CC) $(CFLAG) -o $@ $(OBJ) $(LIBFLAG) $(INCFLAG)
$(LIBDIR)/libft.a:
	make -C $(LIBDIR)/ fclean && make -C $(LIBDIR)/
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir $(OBJDIR) 2> /dev/null || true
	$(CC) $(CFLAG) $(INCFLAG) -o $@ -c $<
clean:
	$(RM) $(OBJ)
	make -C $(LIBDIR)/ clean
	rmdir $(OBJDIR) 2> /dev/null || true
fclean: clean
	make -C $(LIBDIR)/ fclean
	$(RM) $(NAME)
re: fclean all
debug : fclean $(OBJ)
	$(CC) $(CFLAG) $(DEBUGCC) -o $(NAME) $(OBJ) $(LIBFLAG) $(INCFLAG)
run: all
	@sh runner.sh
.PHONY: all, $(NAME), clean, fclean, re, debug, run
