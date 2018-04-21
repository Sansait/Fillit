/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:18:58 by nihuynh           #+#    #+#             */
/*   Updated: 2018/04/20 14:07:47 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H

# include "libft.h"
# define BUFF_SIZE 546
# define MSG_ERROR "error"
# define MSG_USAGE "usage: fillit [] map_file.fillit"

# define DEBUG 0

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_tetro
{
	t_point		hash[4];
	int			length;
	int			width;
	char		c;
}				t_tetro;
/*
** Functions in parser.c :
** Read the file from a safe and open fd.
*/
t_list			ft_parse(int fd);
/*
** Functions in utils_tool.c :
** ft_exit_error : Commun exit for every error encounter during the program.
** ft_exit_usage : Exit if there is a issues while calling the executable.
*/
void			ft_exit_error(void);
void			ft_exit_usage(void);
void			ft_exit_clean(void);
/*
** Handle the 2 types of output for the tiles (isvalid can exit the program).
*/
int				tile_ishash(char c);
int				tile_notvalid(char c);
/*
** Functions in parse_tools.c :
** built_point: Create a point from postion x and y.
** check_links : Calculate the link_count of a hash tile.
** set_tetro : Set the length and width of a tetro node and normalize hash[4].
*/
t_point			built_point(int x, int y);
int				check_links(int select, t_point pos_set[4]);
void			set_tetro(t_tetro **pnode);
/*
** Functions in display.c :
** ONLY PRINT IF DEBUG IS AT 1
*/
void			print_int(char *name, int value);
void			print_pos_set(t_point set[4]);
void			print_lst_tetro(t_list *lst_tetro);
/*
** Functions in display.c :
** Backtracking solution finder :
*/
int				ft_solver(t_list tetra);
/*
** Functions of solver_tools.c
*/
char			**ft_init_map(int sqr_size);
int				ft_roundup_sqrt(int n);
char			**ft_place_tetra(t_tetro *tetra, char **greed, int x, int y);
char			**ft_remove_tetra(t_tetro *tetra, char **greed, int x, int y);
void			ft_delete_map(char ***greed, int sqr_size);

#endif
