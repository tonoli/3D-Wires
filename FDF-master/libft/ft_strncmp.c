/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:05:57 by aliandie          #+#    #+#             */
/*   Updated: 2015/01/30 15:43:29 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	*tmp2;

	tmp = (unsigned char*)s1;
	tmp2 = (unsigned char*)s2;
	i = 0;
	while ((tmp[i] || tmp2[i]) && (i < n))
	{
		if (tmp[i] < tmp2[i])
			return (-1);
		if (tmp[i] > tmp2[i])
			return (1);
		i++;
	}
	return (0);
}
