/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:45:46 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/21 15:48:29 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow(unsigned int power)
{
	int					dix;

	if (power == 0)
		return (1);
	dix = 1;
	while (power != 0)
	{
		dix = dix * 10;
		power--;
	}
	return (dix);
}

static int	ft_ispower(int n)
{
	int	power;

	power = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		power++;
	}
	return (power);
}

char		*ft_itoa(int n)
{
	char				*str;
	int					i;
	int					power;
	int					len;
	unsigned int		nbr;

	i = 0;
	nbr = ABS(n);
	power = ft_ispower(n);
	len = power + 2;
	if (n < 0)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	if (n < 0)
		str[i++] = '-';
	while (power != 0)
	{
		str[i++] = nbr / ft_pow(power) + '0';
		nbr = nbr % ft_pow(power--);
	}
	str[i] = nbr + '0';
	str[i + 1] = '\0';
	return (str);
}
