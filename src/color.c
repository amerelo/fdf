/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 17:47:10 by amerelo           #+#    #+#             */
/*   Updated: 2016/06/15 19:46:05 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	color(int col)
{
	static int color[1200] = {MAG};

	return (color[col]);
}
