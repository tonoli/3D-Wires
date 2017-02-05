/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:05:00 by aliandie          #+#    #+#             */
/*   Updated: 2015/01/30 15:31:30 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!alst || !*alst)
		return ;
	tmp = *alst;
	if (tmp->content)
		del(tmp->content, tmp->content_size);
	ft_memdel((void**)alst);
}
