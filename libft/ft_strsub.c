/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:50:29 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/30 15:45:58 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sol;
	int		x;

	x = 0;
	sol = (char *)malloc(sizeof(char) * (len + 1));
	if (!sol)
		return (NULL);
	while (s[start] && len--)
	{
		sol[x] = s[start];
		x++;
		start++;
	}
	sol[x] = '\0';
	return (sol);
}
