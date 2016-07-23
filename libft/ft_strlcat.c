/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:27:36 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/26 12:27:46 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	y;

	x = ft_strlen((const char *)dst);
	y = ft_strlen(src);
	if (size <= x)
		return (size + y);
	if (x + y < size)
		ft_strcat(dst, src);
	else
		ft_strncat(dst, src, (y - (x + y - (size - 1))));
	return (x + y);
}
