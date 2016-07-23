/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 19:57:50 by amerelo           #+#    #+#             */
/*   Updated: 2016/06/18 19:19:22 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_to_img(t_lst *start, t_lst *end, t_box box, int color)
{
	int dis;

	(void)end;
	if (start->tmpx >= 0 && start->tmpx < WINX &&
	start->tmpy >= 0 && start->tmpy < WINY)
	{
		dis = ((start->tmpx) * 4) + ((start->tmpy) * box.img_bpl);
		if (start->print_z < 0 && end->print_z < 100)
		{
			box.img[dis] = 0;
			box.img[dis + 1] = 140;
			box.img[dis + 2] = 0;
		}
		else
		{
			box.img[dis] = color & 0x000000FF;
			box.img[dis + 1] = (color & 0x0000FF00) >> 8;
			box.img[dis + 2] = (color & 0x00FF0000) >> 16;
			box.img[dis + 3] = (color & 0xFF000000) >> 24;
		}
	}
}

void	create_line(t_lst *start, t_lst *end, t_box box)
{
	int i;

	i = 0;
	start->tmpx = start->print_x;
	start->tmpy = start->print_y;
	if (box.line.d_x > box.line.d_y)
		while (i++ <= box.line.d_x)
		{
			put_pixel_to_img(start, end, box, color((i + 100) % 700));
			start->tmpx += box.line.xincr;
			box.line.ex -= box.line.dy;
			if (box.line.ex < 0 && (start->tmpy += box.line.yincr))
				box.line.ex += box.line.dx;
		}
	else
		while (i++ <= box.line.d_y)
		{
			put_pixel_to_img(start, end, box, color((i + 100) % 700));
			start->tmpy += box.line.yincr;
			box.line.ey -= box.line.dx;
			if (box.line.ey < 0 && (start->tmpx += box.line.xincr))
				box.line.ey += box.line.dy;
		}
}

void	f_line(t_lst *start, t_lst *end, t_box box)
{
	box.line.ex = abs(end->print_x - start->print_x);
	box.line.ey = abs(end->print_y - start->print_y);
	box.line.dx = 2 * box.line.ex;
	box.line.dy = 2 * box.line.ey;
	box.line.d_y = box.line.ey;
	box.line.d_x = box.line.ex;
	box.line.yincr = (start->print_y > end->print_y) ? -1 : 1;
	box.line.xincr = (start->print_x > end->print_x) ? -1 : 1;
	create_line(start, end, box);
}

void	put_img(t_box box)
{
	t_lst	*info;

	info = box.head;
	while (info)
	{
		if (info->down)
			f_line(info, info->down, box);
		if (info->next && info->ty == info->next->ty)
			f_line(info, info->next, box);
		info = info->next;
	}
	mlx_put_image_to_window(box.mlx_ptr, box.win_ptr, box.img_ptr, 0, 0);
}
