/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:18:58 by nihuynh           #+#    #+#             */
/*   Updated: 2018/04/16 23:51:00 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H

# include "libft.h"

# define BUFF_SIZE 546
# define MSG_ERROR "error"
# define MSG_USAGE "usage: fillit [] map_file.fillit"
# define ASSERT(test) (test) ? ((void) 0) : ft_exit_error()

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_tetro
{
	t_point		hash1;
	t_point		hash2;
	t_point		hash3;
	t_point		hash4;
	int			length;
	int			width;
}				t_tetro;

/*
** Commun exit for every error encounter during the program.
*/
void			ft_exit_error(void);
/*
** Exit if there is a issues while calling the executable.
*/
void			ft_exit_usage(void);
/*
** Verify that the format of the map is OK.
*/
void			ft_fastcheck(char *data, int tetro_count);
/*
** Verify that the charset of the map is OK & call the parcer.
*/
t_list			ft_slowcheck(char *data, int tetro_count);
/*
** Built a tetro struct from the map string.
*/
t_tetro			ft_built_tetro(char **data);
/*
** Fetch a packet from the open file.
*/
char			*ft_parse(int fd);

#endif
