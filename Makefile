# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/16 18:24:33 by nihuynh           #+#    #+#              #
#    Updated: 2018/04/19 11:26:27 by sklepper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Config Fillit:
NAME	:=	fillit
SRC		:=	main.c utils_tools.c display.c \
			parser.c  parse_tools.c \
			solver.c solver_tools.c
HEAD	:=	fillit.h Libft/libft.h
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
MAPDIR		:=	./map
MAPERROR	:=	empty_square.fillit full_square.fillit less_hash_00.fillit \
				less_hash.fillit more_hash.fillit
MAPVALID	:=	5,11s.fillit 8,11s.fillit 9,63s.fillit 10,8s.fillit \
				12,04s.fillit 14,10s.fillit 17,70s.fillit 28,97s.fillit
MAP_ERR		:=	$(addprefix $(MAPDIR)/, $(MAPERROR))
MAP_VALID	:=	$(addprefix $(MAPDIR)/, $(MAPVALID))
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
debug : fclean $(OBJ)
	$(CC) $(CFLAG) $(DEBUGCC) -o $(NAME) $(OBJ) $(LIBFLAG) $(INCFLAG)
run: re
	@echo "\nRunning error maps : "
	@sh map_runner.sh $(MAP_ERR)
	@echo "\nRunning valid maps : "
	@sh map_runner.sh $(MAP_VALID)
.PHONY: all, $(NAME), clean, fclean, re, debug
