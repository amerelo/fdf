/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 18:19:27 by amerelo           #+#    #+#             */
/*   Updated: 2016/06/15 20:14:44 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_quit(void)
{
	exit(0);
}

void	ft_initlist(t_box *box, t_lst **info)
{
	if (!box->head)
	{
		*info = (t_lst *)malloc(sizeof(t_lst));
		box->head = *info;
		(*info)->next = NULL;
		(*info)->down = NULL;
	}
	else
	{
		(*info)->next = (t_lst *)malloc(sizeof(t_lst));
		(*info) = (*info)->next;
		(*info)->next = NULL;
		(*info)->down = NULL;
	}
}

void	ft_free(char **tmp)
{
	int x;

	x = 0;
	while (tmp[x])
	{
		free(tmp[x]);
		++x;
	}
	free(tmp);
}

void	init_box(t_box *box)
{
	box->img_ptr = NULL;
	box->mlx_ptr = NULL;
	box->win_ptr = NULL;
	box->head = NULL;
	box->img_bpp = 0;
	box->img_bpl = 0;
	box->endian = 0;
	box->max_x = 0;
	box->max_y = 0;
	box->radx = 0;
	box->rady = 0;
	box->radz = 0;
	box->db = 0;
	box->up_do = 0;
	box->le_ri = 0;
	box->alti = 1;
}
