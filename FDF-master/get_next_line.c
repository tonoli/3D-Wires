/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 15:47:34 by aliandie          #+#    #+#             */
/*   Updated: 2015/02/04 13:10:40 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_join(char **line, char *buf, int nb)
{
	char	*tmp;

	tmp = *line;
	buf[nb] = '\0';
	(*line) = ft_strjoin(*line, buf);
	free(tmp);
}

static void	ft_sub(char **line, char **buffer)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strsub(*line, 0, *buffer - *line);
	*buffer = *buffer + 1;
	*buffer = ft_strdup(*buffer);
	free(tmp);
}

int			get_next_line(int const fd, char **line)
{
	static char	*buffer;
	char		*buf;
	int			nb;

	buf = malloc(sizeof(char) * BUFF_SIZE + 1);
	if (fd != -1 && buf != NULL)
	{
		*line = ft_strnew(1);
		if (buffer != NULL)
		{
			*line = ft_strdup(buffer);
			free(buffer);
		}
		while (((buffer = ft_strchr(*line, '\n')) == NULL)
			&& ((nb = read(fd, buf, BUFF_SIZE)) > 0))
			ft_join(line, buf, nb);
		if (nb == 0 && buffer == NULL)
			return (0);
		nb = (nb == -1) ? -1 : 1;
		ft_sub(line, &buffer);
		free(buf);
		return (nb);
	}
	else
		return (-1);
}
