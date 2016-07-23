/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:08:42 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/27 18:08:47 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	x;

	x = 0;
	if (n == 0)
		return (1);
	while ((unsigned char)s1[x] == (unsigned char)s2[x] && s1[x] &&
		s2[x] && n--)
	{
		if (n == 0 && (unsigned char)s1[x] == (unsigned char)s2[x])
			return (1);
		else if (n == 0 && (unsigned char)s1[x] != (unsigned char)s2[x])
			return (0);
		x++;
	}
	if ((unsigned char)s1[x] == (unsigned char)s2[x])
		return (1);
	else
		return (0);
}
