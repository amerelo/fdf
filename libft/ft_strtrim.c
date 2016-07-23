/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:31:12 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/28 18:32:04 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*tmp;
	size_t	x;
	size_t	y;
	size_t	o;

	x = 0;
	o = 0;
	y = ft_strlen(s);
	while ((s[x] == ' ') || (s[x] == '\n') || (s[x] == '\t'))
		x++;
	while (((s[y - 1] == ' ') || (s[y - 1] == '\n') || (s[y - 1] == '\t')) && \
			(x != y))
		y--;
	tmp = (char *)malloc(sizeof(char) * ((y - x) + 1));
	if (!tmp)
		return (NULL);
	while (y - (o + x))
	{
		tmp[o] = s[x + o];
		o++;
	}
	tmp[o] = '\0';
	return (tmp);
}
