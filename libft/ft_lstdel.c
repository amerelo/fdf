/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:40:22 by amerelo           #+#    #+#             */
/*   Updated: 2015/12/02 19:40:24 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (alst != NULL && del != NULL)
	{
		while ((*alst) != NULL)
		{
			(*del)(*alst, (*alst)->content_size);
			tmp = (*alst);
			(*alst) = tmp->next;
			free(tmp);
		}
	}
}
