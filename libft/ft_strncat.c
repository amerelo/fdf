/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:34:24 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/24 18:34:31 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = s1;
	while (s1[i])
		i++;
	while (n--)
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
