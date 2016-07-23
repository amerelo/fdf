/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:40:39 by amerelo           #+#    #+#             */
/*   Updated: 2016/06/15 20:14:02 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	matrix(t_box *box, int newx, int newy, int newz)
{
	t_lst	*map;
	int		tmp_cor;
	int		border_x;
	int		border_y;

	border_x = (WINX - (box->size_max * box->max_x));
	border_y = (WINY - (box->size_max * box->max_y));
	map = box->head;
	while (map)
	{
		newy = (map->y - (box->size_max * box->max_y / 2));
		newx = (map->x - (box->size_max * box->max_x / 2));
		newz = map->z * box->alti;
		map->print_y = (newy * cos(box->radx)) + (newz * -sin(box->radx));
		tmp_cor = (newy * sin(box->radx)) + (newz * cos(box->radx));
		map->print_z = (newx * -sin(box->rady)) + (tmp_cor * cos(box->rady));
		tmp_cor = (newx * cos(box->rady)) + (tmp_cor * sin(box->rady));
		map->print_x = (tmp_cor * cos(box->radz)) +
		(map->print_y * -sin(box->radz));
		map->print_y = (tmp_cor * sin(box->radz)) +
		(map->print_y * cos(box->radz));
		map->print_y += border_y + box->up_do;
		map->print_x += border_x + box->le_ri;
		map = map->next;
	}
}

int		distance_between_points(t_box *box)
{
	int		size_min;
	t_lst	*tmp;

	tmp = box->head;
	size_min = (WINX < WINY) ? WINX : WINY;
	box->size_max = (size_min - (int)(size_min * 0.1)) /
	((box->max_x >= box->max_y) ? box->max_x : box->max_y);
	box->size_max += box->db;
	while (tmp)
	{
		tmp->x = (tmp->tx * box->size_max);
		tmp->y = (tmp->ty * box->size_max);
		tmp = tmp->next;
	}
	return (1);
}

int		ft_creat_list(int fd, char *line, char **tmp)
{
	t_box	box;

	init_box(&box);
	if (!get_map(fd, line, tmp, &box))
		return (0);
	ft_creat_down(&box);
	if (!(box.mlx_ptr = mlx_init()) ||
	!(box.win_ptr = mlx_new_window(box.mlx_ptr, WINX, WINY, "FDF")) ||
	!(box.img_ptr = mlx_new_image(box.mlx_ptr, WINX, WINY)) ||
	!(box.img = mlx_get_data_addr(box.img_ptr, &box.img_bpp,
	&box.img_bpl, &box.endian)))
		return (0);
	do_stuff(&box);
	mlx_hook(box.win_ptr, 17, (1L << 17), ft_quit, &box);
	mlx_hook(box.win_ptr, 2, (1L << 0), detect, &box);
	mlx_loop(box.mlx_ptr);
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	**tmp;

	line = NULL;
	tmp = NULL;
	if (ac != 2)
		ft_putendl("error");
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd <= 0)
			ft_putendl("error");
		if (!ft_creat_list(fd, line, tmp))
			ft_putendl("error");
	}
	return (0);
}
