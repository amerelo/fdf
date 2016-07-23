/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:48:31 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/23 19:48:35 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	int		x;
	char	*cpy;

	cpy = NULL;
	x = 0;
	cpy = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	while (str[x] != '\0')
	{
		cpy[x] = str[x];
		x++;
	}
	cpy[x] = 0;
	return (cpy);
}
