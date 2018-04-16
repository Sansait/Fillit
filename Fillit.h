#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H
# define BUFF_SIZE 546

#include "Libft/libft.h"

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_tetrominos
{
	t_point					hash1;
	t_point					hash2;
	t_point					hash3;
	t_point					hash4;
	int						length;
	int						width;
	struct s_tetrominos		*next;
}				t_list;

#endif
