/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 10:51:34 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/28 10:51:38 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *res;

	res = (char *)malloc(sizeof(char) * (size));
	if (!res)
		return (NULL);
	ft_memset((void *)res, '\0', size);
	return (res);
}
