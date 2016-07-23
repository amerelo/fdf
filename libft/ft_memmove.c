/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:37:08 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/25 12:37:15 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	while (dst > src && len)
	{
		((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
		len--;
	}
	i = 0;
	while (dst < src && len)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
		len--;
	}
	return (dst);
}
