/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 19:52:07 by amerelo           #+#    #+#             */
/*   Updated: 2016/07/12 23:52:55 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation(int keycode, t_box *box)
{
	if (keycode == 91 && (box->radx += 0.1))
		;
	if (keycode == 87 && (box->radx -= 0.1))
		;
	if (keycode == 88 && (box->rady += 0.1))
		;
	if (keycode == 86 && (box->rady -= 0.1))
		;
	if (keycode == 89 && (box->radz += 0.1))
		;
	if (keycode == 92 && (box->radz -= 0.1))
		;
}

void	reset(t_box *box)
{
	box->radx = 0;
	box->rady = 0;
	box->radz = 0;
	box->db = 0;
	box->up_do = 0;
	box->le_ri = 0;
	box->alti = 1;
	distance_between_points(box);
}

void	move(int keycode, t_box *box)
{
	if (keycode == 126 && (box->up_do -= 20))
		;
	if (keycode == 125 && (box->up_do += 20))
		;
	if (keycode == 124 && (box->le_ri += 20))
		;
	if (keycode == 123 && (box->le_ri -= 20))
		;
}

int		detect(int keycode, t_box *box)
{
	rotation(keycode, box);
	move(keycode, box);
	if (keycode == 18 && (box->db += 1) &&
	distance_between_points(box))
		;
	if (keycode == 19 && box->db + box->size_max > 0 &&
	(box->db -= 1) && distance_between_points(box))
		;
	if (keycode == 83 && (box->alti += 1))
		;
	if (keycode == 84 && (box->alti -= 1))
		;
	if (keycode == 82)
		reset(box);
	if (keycode == 53)
		ft_quit();
	ft_bzero(box->img, (WINX * WINY * 4));
	do_stuff(box);
	return (1);
}

int		do_stuff(t_box *box)
{
	matrix(box, 0, 0, 0);
	put_img(*box);
	return (1);
}
