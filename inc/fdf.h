/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:33:37 by amerelo           #+#    #+#             */
/*   Updated: 2016/06/21 17:05:57 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <mlx.h>
# include <math.h>
# define WINX 500
# define WINY 500

typedef struct			s_lst
{
	int					ty;
	int					tx;
	int					x;
	int					y;
	int					z;
	int					tmpx;
	int					tmpy;
	int					print_x;
	int					print_y;
	int					print_z;
	struct s_lst		*next;
	struct s_lst		*down;
}						t_lst;

typedef struct			s_line
{
	int					ex;
	int					ey;
	int					dx;
	int					dy;
	int					d_x;
	int					d_y;
	int					xincr;
	int					yincr;
}						t_line;

typedef struct			s_box
{
	void				*img_ptr;
	void				*mlx_ptr;
	void				*win_ptr;
	int					img_bpp;
	int					img_bpl;
	int					endian;
	int					max_x;
	int					max_y;
	int					size_max;
	int					maxsize;
	char				*img;
	double				radx;
	double				rady;
	double				radz;
	double				db;
	int					up_do;
	int					le_ri;
	int					alti;
	t_line				line;
	t_lst				*head;
}						t_box;

void					ft_creat_down(t_box *box);
int						get_map(int fd, char *line, char **tmp, t_box *box);
void					ft_initlist(t_box *box, t_lst **info);
void					ft_free(char **tmp);
void					init_box(t_box *box);
int						ft_quit(void);
int						color(int col);
int						do_stuff(t_box *box);
int						do_stuff(t_box *box);
int						detect(int keycode, t_box *box);
void					move(int keycode, t_box *box);
void					reset(t_box *box);
void					rotation(int keycode, t_box *box);
int						distance_between_points(t_box *box);
void					matrix(t_box *box, int newx, int newy, int newz);
void					put_img(t_box box);
void					put_pixel_to_img(t_lst *start, t_lst *end, t_box box,
int color);
void					create_line(t_lst *start, t_lst *end, t_box box);
void					f_line(t_lst *start, t_lst *end, t_box box);
void					put_img(t_box box);

#endif
