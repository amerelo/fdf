/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:52:38 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/25 09:52:41 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int			x;

	if (*s2 == 0)
		return ((char *)s1);
	while (*s1)
	{
		x = 0;
		while (s1[x] == s2[x] && s1[x] && s2[x])
			x++;
		if (s2[x] == '\0')
			return ((char *)s1);
		s1++;
	}
	return (0);
}
