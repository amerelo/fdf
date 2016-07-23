/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:43:11 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/28 11:43:13 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *res;

	res = (char *)malloc(sizeof(char) * size);
	if (!res)
		return (NULL);
	ft_memset((void *)res, '\0', size);
	return (res);
}
