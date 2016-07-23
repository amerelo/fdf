/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:27:52 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/25 14:27:57 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		x;

	x = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[x] == (unsigned char)s2[x] && s1[x] &&
		s2[x] && n--)
	{
		if (n == 0)
			return ((unsigned char)s1[x] - (unsigned char)s2[x]);
		x++;
	}
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
