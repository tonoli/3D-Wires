/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 13:47:47 by aliandie          #+#    #+#             */
/*   Updated: 2015/01/30 15:30:58 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!alst || !*alst)
		return ;
	tmp = *alst;
	while (tmp)
	{
		if (tmp->content)
			(*del)(tmp->content, tmp->content_size);
		tmp = tmp->next;
	}
	*alst = NULL;
}
