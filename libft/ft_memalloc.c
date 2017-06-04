/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:22:35 by itonoli-          #+#    #+#             */
/*   Updated: 2016/11/28 10:38:42 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*a;

	a = NULL;
	a = (void *)malloc(sizeof(void) * size);
	if (a)
	{
		ft_bzero(a, size);
		return (a);
	}
	return (NULL);
}
