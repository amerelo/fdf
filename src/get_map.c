/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 18:15:08 by amerelo           #+#    #+#             */
/*   Updated: 2016/06/15 20:14:27 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_reajust(t_lst **fast, t_box *slow, double size_max)
{
	if ((*fast) && slow->head->ty == (*fast)->ty)
		while ((*fast) && slow->head->ty == (*fast)->ty)
		{
			(*fast)->x = ((*fast)->tx * size_max);
			(*fast)->y = ((*fast)->ty * size_max);
			(*fast) = (*fast)->next;
		}
	else
		while (slow->head && slow->head->ty == ((*fast)->ty - 2))
			slow->head = slow->head->next;
}

void	init_down(t_lst *fast, t_box *box)
{
	while (fast && box->head->ty == fast->ty)
	{
		fast->x = (fast->tx * box->size_max);
		fast->y = (fast->ty * box->size_max);
		fast = fast->next;
	}
}

void	ft_creat_down(t_box *box)
{
	t_lst	*fast;
	t_lst	*tmp;
	int		size_min;

	tmp = box->head;
	fast = box->head;
	size_min = ((WINX < WINY) ? WINX : WINY);
	box->size_max = (size_min - (int)(size_min * 0.1)) /
	((box->max_x >= box->max_y) ? box->max_x : box->max_y);
	init_down(fast, box);
	while (fast)
	{
		if ((fast->ty - 1) != box->head->ty)
			ft_reajust(&fast, box, box->size_max);
		if (fast)
		{
			fast->x = (fast->tx * box->size_max);
			fast->y = (fast->ty * box->size_max);
			box->head->down = fast;
			fast = fast->next;
			box->head = box->head->next;
		}
	}
	box->head = tmp;
}

int		get_map(int fd, char *line, char **tmp, t_box *box)
{
	t_lst	*info;
	int		y;
	int		x;

	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(tmp = ft_strsplit(line, ' ')) || !tmp[0])
			return (0);
		x = 0;
		while (tmp[x])
		{
			ft_initlist(box, &info);
			box->max_x = (x > box->max_x) ? x : box->max_x;
			info->z = ft_atoi(tmp[x]);
			info->ty = y;
			info->tx = x++;
		}
		ft_free(tmp);
		free(line);
		box->max_y = (++y > box->max_y) ? y : box->max_y;
	}
	--box->max_x;
	--box->max_y;
	return (1);
}
