/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:11:29 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/25 13:11:38 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int		x;

	x = 0;
	while ((unsigned char)s1[x] == (unsigned char)s2[x] && s1[x] && s2[x])
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
