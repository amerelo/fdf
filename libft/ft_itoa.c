/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 11:08:25 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/29 11:08:28 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	intlen(int n)
{
	size_t			x;
	unsigned int	v;

	x = 1;
	v = n;
	if (n < 0)
	{
		x++;
		v = (unsigned int)n * (-1);
	}
	while (v >= 10)
	{
		v = (v / 10);
		x++;
	}
	return (x);
}

char			*ft_itoa(int n)
{
	char			*tmp;
	size_t			size;
	unsigned int	x;

	if (n == 0)
		return (ft_strdup("0"));
	size = intlen(n);
	tmp = (char *)malloc(sizeof(char) * (size));
	if (!tmp)
		return (NULL);
	x = n;
	if (n < 0)
	{
		x = (unsigned int)n * -1;
		tmp[0] = '-';
	}
	tmp[size--] = '\0';
	while (x)
	{
		tmp[size--] = ((x % 10) + '0');
		x = (x / 10);
	}
	return (tmp);
}
