/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 15:40:40 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/21 16:13:12 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strpos(char *str, char c)
{
	char	*start;

	start = str;
	while (*str)
	{
		if (*str == c)
			return (str - start);
		str++;
	}
	return (str - start);
}

static long		ft_strtol_rec(char **str, int sign, int base)
{
	long	endptr;
	int		i;

	endptr = 0;
	while (**str && (i = ft_strpos(ALPHABET, ft_tolower(**str))) < base)
	{
		if (sign == -1)
			endptr = endptr * base - i;
		else
			endptr = endptr * base + i;
		(*str)++;
	}
	return (endptr);
}

long			ft_strtol(char *str, char **endptr, int base)
{
	int		sign;
	long	result;

	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign = -1;
		}
		str++;
	}
	result = ft_strtol_rec(&str, sign, base);
	*endptr = str;
	return (result);
}
