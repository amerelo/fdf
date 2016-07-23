/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:41:31 by amerelo           #+#    #+#             */
/*   Updated: 2015/11/28 13:41:40 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int	x;

	x = 0;
	while (s[x])
	{
		ft_putchar_fd(s[x], fd);
		x++;
	}
	ft_putchar_fd('\n', fd);
}
