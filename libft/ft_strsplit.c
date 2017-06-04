/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 21:06:56 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/21 11:35:38 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_spliter(char **dest, char const *str, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] == '\0')
			return (dest);
		while (str[i] != c && str[i] != '\0')
			dest[k][j++] = str[i++];
		dest[k][j] = '\0';
		j = 0;
		k++;
	}
	return (dest);
}

static int	ft_count_words(char const *str, char c)
{
	int i;
	int m;

	i = 0;
	m = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] == '\0')
			return (m);
		m++;
		while (str[i] != c && str[i] != '\0')
			i++;
		if (str[i] == '\0')
			return (m);
	}
	return (m);
}

static int	*ft_count_letters(int *tab, char const *str, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 1;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] == '\0')
			return (tab);
		while (str[i] != c && str[i] != '\0')
		{
			i++;
			j++;
		}
		tab[k] = j - 1;
		j = 1;
		k++;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		m;
	int		*tab;
	char	**dest;

	if (!s)
		return (NULL);
	i = -1;
	m = ft_count_words(s, c);
	if (!(tab = (int *)malloc((sizeof(int)) * m + 1)))
		return (NULL);
	tab = ft_count_letters(tab, s, c);
	if (!(dest = (char **)malloc((sizeof(char *)) * m + 1)))
		return (NULL);
	while (++i < m)
		dest[i] = (char *)malloc(sizeof(char) * tab[i]);
	dest = ft_spliter(dest, s, c);
	free(tab);
	dest[m] = 0;
	return (dest);
}
