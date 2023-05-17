/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizehexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:04:00 by abeaudui          #+#    #+#             */
/*   Updated: 2023/05/17 16:04:03 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_sizehexa_m(unsigned int n)
{
	char	c;

	if (n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else if (n < 16)
	{
		c = n - 10 + 'a';
		write (1, &c, 1);
	}
	else
	{
		ft_sizehexa_m(n / 16);
		if (n % 16 <= 9)
			c = n % 16 + '0';
		else
			c = n % 16 - 10 + 'a';
		write (1, &c, 1);
	}
}

static void	ft_sizehexa_maj(unsigned int n)
{
	char	c;

	if (n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else if (n < 16)
	{
		c = n - 10 + 'A';
		write (1, &c, 1);
	}
	else
	{
		ft_sizehexa_maj(n / 16);
		if (n % 16 <= 9)
			c = n % 16 + '0';
		else
			c = n % 16 - 10 + 'A';
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
		n /= 16;
		cpt++;
	}
	return (cpt);
}

int	ft_sizehexa(unsigned int n, char c)
{
	if (c == 'x')
	{
		ft_sizehexa_m(n);
		return (ft_taille(n));
	}
	if (c == 'X')
	{
		ft_sizehexa_maj(n);
		return (ft_taille(n));
	}
	return (0);
}
