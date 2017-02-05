/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 12:53:00 by aliandie          #+#    #+#             */
/*   Updated: 2015/01/30 15:37:16 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*tmp;

	new_lst = (t_list*)malloc(sizeof(t_list));
	if (new_lst == NULL || !lst || !(*f))
		return (NULL);
	tmp = f(lst);
	new_lst = tmp;
	while (lst->next)
	{
		lst = lst->next;
		new_lst->next = f(lst);
		new_lst = new_lst->next;
	}
	new_lst = NULL;
	new_lst = tmp;
	return (new_lst);
}
