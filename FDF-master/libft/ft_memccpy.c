/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 13:54:00 by aliandie          #+#    #+#             */
/*   Updated: 2015/01/30 15:41:19 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned	char	*strd;
	unsigned	char	*strs;

	i = 0;
	if (dst == NULL || src == NULL)
		return (NULL);
	strd = (unsigned char*)dst;
	strs = (unsigned char*)src;
	while (i < n)
	{
		strd[i] = strs[i];
		if (strs[i] == (unsigned char)c)
			return (&strd[i + 1]);
		i++;
	}
	return (NULL);
}
