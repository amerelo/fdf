/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:50:00 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/30 11:50:02 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		x;

	x = 0;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(s));
	if (!tmp)
		return (NULL);
	while (s[x])
	{
		tmp[x] = (*f)(s[x]);
		x++;
	}
	return (tmp);
}
