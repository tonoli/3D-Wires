/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 15:41:58 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/21 15:44:50 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_power(int valeur, int power)
{
	int rslt;

	rslt = 1;
	if (power == 0)
		return (1);
	while (power)
	{
		rslt *= valeur;
		power--;
	}
	return (rslt);
}
