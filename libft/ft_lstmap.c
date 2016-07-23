/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 21:20:05 by amerelo           #+#    #+#             */
/*   Updated: 2015/12/02 21:20:08 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *start;

	if (lst && f)
	{
		new = (*f)(lst);
		if (new)
		{
			start = new;
			while (lst->next)
			{
				lst = lst->next;
				new->next = (*f)(lst);
				new = new->next;
				if (new->next)
					return (NULL);
			}
			return (start);
		}
	}
	return (NULL);
}
