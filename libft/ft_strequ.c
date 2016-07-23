/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 10:34:35 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/28 10:34:38 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	x;

	x = 0;
	while ((unsigned char)s1[x] == (unsigned char)s2[x] && s1[x] && s2[x])
		x++;
	if ((unsigned char)s1[x] == (unsigned char)s2[x])
		return (1);
	else
		return (0);
}
