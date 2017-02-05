/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:03:00 by aliandie          #+#    #+#             */
/*   Updated: 2015/02/03 18:03:31 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		gnl_counter(char *f, char *line)
{
	int		fd;
	int		i;

	fd = open(f, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) == 1)
		i++;
	close(fd);
	return (i);
}
