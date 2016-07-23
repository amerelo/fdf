/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:33:55 by amerelo           #+#    #+#             */
/*   Updated: 2016/06/04 17:02:00 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int x;
	int sign;
	int resu;

	x = 0;
	sign = 1;
	resu = 0;
	if (str == NULL)
		return (0);
	while (str[x] == '\t' || str[x] == '\n' || str[x] == '\v' ||
	str[x] == '\f' || str[x] == '\r' || str[x] == ' ')
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		sign = (str[x] == '-') ? -1 : 1;
		x++;
	}
	while (str[x])
	{
		if (str[x] < '0' || str[x] > '9')
			return (sign * resu);
		resu = resu * 10 + str[x] - '0';
		x++;
	}
	return (sign * resu);
}
