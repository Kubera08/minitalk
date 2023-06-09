/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_unsignedint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:03:47 by abeaudui          #+#    #+#             */
/*   Updated: 2023/05/17 16:03:50 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_size_unsignedint_pos(unsigned int n)
{
	char	c;

	if (n <= 9)
	{
		c = n + '0';
		write (1, &c, 1);
	}
	else
	{
		c = n % 10 + '0';
		n = n / 10;
		ft_size_unsignedint_pos(n);
		write (1, &c, 1);
	}
}

static int	ft_taille(unsigned int n)
{
	int	cpt;

	cpt = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		cpt++;
	}
	return (cpt);
}

int	ft_size_unsignedint(unsigned int n)
{
	ft_size_unsignedint_pos(n);
	return (ft_taille(n));
}
