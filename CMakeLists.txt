cmake_minimum_required(VERSION 3.9)
project(Fillit C)

set(CMAKE_C_STANDARD 99)

set(SOURCES ${SOURCES} main.c display.c map.c reader.c solver.c toolbox.c parse_tools.c
        Libft/ft_bzero.c
        Libft/ft_itoa.c
        Libft/ft_memalloc.c
        Libft/ft_memcpy.c
        Libft/ft_memccpy.c
        Libft/ft_memchr.c
        Libft/ft_memdel.c
        Libft/ft_memmove.c
        Libft/ft_memset.c
        Libft/ft_power.c
        Libft/ft_putchar.c
        Libft/ft_putchar_fd.c
        Libft/ft_putendl_fd.c
        Libft/ft_putendl.c
        Libft/ft_putnbr_fd.c
        Libft/ft_putnbr.c
        Libft/ft_putstr_fd.c
        Libft/ft_putstr.c
        Libft/ft_puttab.c
        Libft/ft_strclr.c
        Libft/ft_strdel.c
        Libft/ft_strequ.c
        Libft/ft_striter.c
        Libft/ft_striteri.c
        Libft/ft_strjoin.c
        Libft/ft_strlen.c
        Libft/ft_strmap.c
        Libft/ft_strmapi.c
        Libft/ft_strequ.c
        Libft/ft_strnew.c
        Libft/ft_strnequ.c
        Libft/ft_strsplit.c
        Libft/ft_strsub.c
        Libft/ft_strtrim.c
        Libft/ft_memcmp.c
        Libft/ft_memcmp.c
        Libft/ft_strdup.c
        Libft/ft_strcpy.c
        Libft/ft_strcat.c
        Libft/ft_strncat.c
        Libft/ft_strlcat.c
        Libft/ft_strchr.c
        Libft/ft_strrchr.c
        Libft/ft_strstr.c
        Libft/ft_strnstr.c
        Libft/ft_strcmp.c
        Libft/ft_strncmp.c
        Libft/ft_atoi.c
        Libft/ft_isalpha.c
        Libft/ft_isdigit.c
        Libft/ft_isascii.c
        Libft/ft_isprint.c
        Libft/ft_toupper.c
        Libft/ft_tolower.c
        Libft/ft_strncpy.c
        Libft/ft_min.c
        Libft/ft_isalnum.c
        Libft/ft_lstnew.c
        Libft/ft_lstdelone.c
        Libft/ft_lstdel.c
        Libft/ft_lstadd.c
        Libft/ft_lstiter.c
        Libft/ft_lstmap.c
        Libft/ft_max.c
        Libft/ft_lstaddend.c
        Libft/ft_lstsize.c
        Libft/ft_lstlast.c
        Libft/ft_lstat.c
        Libft/ft_lstrev.c
        Libft/libft.h)

add_executable(Fillit ${SOURCES} Libft/libft.a)