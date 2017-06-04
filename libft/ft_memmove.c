/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 21:58:35 by itonoli-          #+#    #+#             */
/*   Updated: 2016/11/29 12:40:53 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str;
	char	*dest;
	size_t	i;

	i = 0;
	str = (char *)src;
	dest = (char *)dst;
	if (str >= dest)
	{
		while (i < len)
		{
			dest[i] = str[i];
			i++;
		}
	}
	else
	{
		while (len)
		{
			dest[len - 1] = str[len - 1];
			len--;
		}
	}
	return (dest);
}
