/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:46:20 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/25 15:46:26 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int			x;
	size_t		v;

	v = n;
	if (*s2 == 0)
		return ((char *)s1);
	while (*s1 && n > 0)
	{
		x = 0;
		while (s1[x] == s2[x] && s1[x] && s2[x] && (n - x) > 0)
			x++;
		if (s2[x] == '\0' || n == 0)
			return ((char *)s1);
		s1++;
		n--;
	}
	return (0);
}
