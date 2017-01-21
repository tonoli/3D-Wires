/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:08:31 by itonoli-          #+#    #+#             */
/*   Updated: 2017/01/21 22:02:45 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stocker(int fd, char **line, char *buf, char **stock)
{
	int		len;
	char	*tmp;
	char	*tmp2;

	tmp = (*stock != NULL) ? (ft_strjoin(*stock, buf)) : (ft_strdup(buf));
	ft_strdel(&buf);
	tmp2 = ft_strchr(tmp, '\n');
	if (tmp2 == NULL)
	{
		ft_strdel(stock);
		*stock = ft_strdup(tmp);
		ft_strdel(&tmp);
		return (get_next_line(fd, line));
	}
	len = ft_strlen(tmp) - ft_strlen(tmp2);
	*line = ft_memalloc(len + 1);
	*line = ft_strncpy(*line, tmp, len);
	ft_strdel(stock);
	*stock = (ft_strcmp(tmp2, "\n") != 0) ? ft_strdup(++tmp2) : NULL;
	ft_strdel(&tmp);
	return (1);
}

int		ft_stock_to_line(char **line, char **stock)
{
	int		len;
	char	*tmp3;

	tmp3 = ft_strchr(*stock, '\n');
	len = ft_strlen(*stock) - ft_strlen(tmp3);
	*line = ft_memalloc(len + 1);
	ft_strncpy(*line, *stock, len);
	(tmp3 != NULL) ? ++tmp3 : 0;
	if (tmp3 == NULL && ft_strcmp(*line, "") == 0)
	{
		stock = NULL;
		return (0);
	}
	*stock = (tmp3 != NULL) ? ft_strdup(tmp3) : NULL;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			*tmp;
	char			buf[BUFF_SIZE];
	static char		*stock;

	ret = read(fd, buf, BUFF_SIZE);
	if (ret == -1 || BUFF_SIZE < 1)
		return (-1);
	if (ret == 0 && stock == NULL)
		return (0);
	if (ret == 0)
		return (ft_stock_to_line(line, &stock));
	if (ret >= 1)
	{
		tmp = (char *)ft_memalloc(ret + 1);
		tmp = ft_strncpy(tmp, buf, ret);
		return (ft_stocker(fd, line, tmp, &stock));
	}
	return (1);
}
