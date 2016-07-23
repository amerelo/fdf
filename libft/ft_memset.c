/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:02:30 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/24 13:02:45 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*x;

	i = 0;
	if (len == 0)
		return (b);
	x = (char *)b;
	while (len--)
	{
		x[i] = c;
		i++;
	}
	return (b);
}
