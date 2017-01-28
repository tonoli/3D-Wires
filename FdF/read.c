/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:08:18 by itonoli-          #+#    #+#             */
/*   Updated: 2017/01/28 20:06:39 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_read(char *path)
{
	int		fd;
	char	*line;
	char	**tab;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		tab = ft_strsplit(line, ' ');
	}
	close (fd);
}
