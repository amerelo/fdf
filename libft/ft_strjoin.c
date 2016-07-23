/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:17:25 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/28 15:17:35 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		y;
	char	*sol;

	x = 0;
	y = 0;
	sol = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!sol)
		return (NULL);
	while (s1[x])
	{
		sol[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		sol[x] = s2[y];
		y++;
		x++;
	}
	sol[x] = '\0';
	return (sol);
}
