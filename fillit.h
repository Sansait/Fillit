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

# define BUFF_SIZE 546
# define MSG_ERROR "error"
# define MSG_USAGE "usage: fillit [] map_file.fillit"
# define HASH '#'
# define TILE '.' || '#'
# define ASSERT(test) (test) ? ((void) 0) : ft_exit_error()

typedef struct	s_point
{
	int 		x;
	int			y;
}				t_point;

typedef struct	s_tetro
{
	t_point		hash[4];
	int			length;
	int			width;
}				t_tetro;

/*
** Read the file from a safe and open fd.
*/
t_list			ft_parse(int fd);

/*
** Functions in toolbox.c :
** ft_exit_error : Commun exit for every error encounter during the program.
** ft_exit_usage : Exit if there is a issues while calling the executable.
*/
void			ft_exit_error(void);
void			ft_exit_usage(void);
/*
** Handle the 2 types of output for the tiles (isvalid can exit the program).
*/
int				tile_ishash(char c);
void			tile_isvalid(char c);
/*
** Create a point from postion x and y.
*/
t_point			built_point(int x, int y);

#endif
