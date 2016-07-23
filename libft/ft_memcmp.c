/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:20:18 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/26 10:20:22 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				x;

	x = 0;
	if (n == 0)
		return (0);
	while (((unsigned char *)s1)[x] == ((unsigned char *)s2)[x] && n--)
	{
		if (n == 0)
			return (((unsigned char *)s1)[x] - ((unsigned char *)s2)[x]);
		x++;
	}
	return (((unsigned char *)s1)[x] - ((unsigned char *)s2)[x]);
}
