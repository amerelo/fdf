/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 18:51:07 by amerelo           #+#    #+#             */
/*   Updated: 2016/02/24 16:22:24 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strjoin_free(char *s1, char *s2, int s)
{
	int		x;
	int		y;
	char	*sol;

	x = s1 != NULL ? ft_strlen(s1) : 0;
	y = s2 != NULL ? ft_strlen(s2) : 0;
	sol = (char *)ft_memalloc(sizeof(char) * (x + y + 1));
	x = 0;
	while (s1 && s1[x])
	{
		sol[x] = s1[x];
		x++;
	}
	if (s1 && (s == 1 || s == 3))
		free(s1);
	y = 0;
	while (s2 && s2[y])
	{
		sol[x + y] = s2[y];
		y++;
	}
	if (s2 && (s == 2 || s == 3))
		free(s2);
	return (sol);
}

static int		ft_check_line(char **stock, char **line)
{
	char *str;
	char *tmp;

	tmp = *stock;
	str = ft_strchr(*stock, '\n');
	if (!str)
		return (0);
	*str = '\0';
	*line = ft_strdup(*stock);
	*stock = ft_strdup(str + 1);
	free(tmp);
	return (1);
}

static int		ft_last_line(char **stock, char **line)
{
	*line = ft_strdup(*stock);
	free(*stock);
	*stock = NULL;
	if (*line[0] == '\0')
	{
		free(*line);
		*line = NULL;
		return (0);
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char		*s[99];
	char			buf[BUFF_SIZE + 1];
	int				r;

	if (fd < 0 || fd > 99 || line == NULL)
		return (-1);
	if (s[fd] && ft_check_line(&(s[fd]), line))
		return (1);
	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		s[fd] = (s[fd] ? ft_strjoin_free(s[fd], buf, 1) : ft_strdup(buf));
		if (ft_check_line(&(s[fd]), line))
			return (1);
	}
	if (s[fd] && r >= 0)
		return (ft_last_line(&(s[fd]), line));
	return (r > 0 ? 1 : r);
}
