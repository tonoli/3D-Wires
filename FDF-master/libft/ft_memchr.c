/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:31:23 by aliandie          #+#    #+#             */
/*   Updated: 2015/01/28 16:14:25 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;

	if (s != NULL)
	{
		str = (unsigned	char*)s;
		i = 0;
		while (i < n)
		{
			if (str[i] == (unsigned char)c)
				return (&str[i]);
			i++;
		}
	}
	return (NULL);
}
