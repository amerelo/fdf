/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:29:37 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/25 19:29:42 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t x;

	x = ft_strlen(s);
	while (s + x >= s)
	{
		if (s[x] == c)
			return ((char *)s + x);
		x--;
	}
	return (0);
}
