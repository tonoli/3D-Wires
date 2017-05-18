/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 21:57:43 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/10 22:05:28 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * In this file you will find all the test main for the functions I use on my fdf program
 */

/*
 * TEST read.c --> OK 
 */

int	main (int argc, char **argv)
{
	t_env env;
	int i = -1;

	if (argc != 2)
	{
		ft_putendl("Error");
		return (0);
	}
	if(ft_read(argv[1], &env))
	{
		ft_putendl("File ERROR 666");
		return (0);
	}
	else
	{
		while (++i < env.lines)
		{
			int j = -1;
			while(++j < env.col)
			{
				ft_putnbr(env.mapi[i][j]);
				ft_putchar(' ');
			}
			ft_putchar('\n');
		}
		return (0);
	}
}

/*
 * TEST 
 */

