/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:02:57 by itonoli-          #+#    #+#             */
/*   Updated: 2016/11/30 18:55:41 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src;
	unsigned char	*dst;
	size_t			i;

	i = 0;
	src = (unsigned char *)s1;
	dst = (unsigned char *)s2;
	if ((s1 || s2) && n != 0)
	{
		while ((i < (n - 1)) && src[i] == dst[i])
			i++;
		return (src[i] - dst[i]);
	}
	else
		return (0);
}
