/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:04:06 by abeaudui          #+#    #+#             */
/*   Updated: 2023/05/17 16:04:12 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sizeint(int n)
{
	int	size;
	int	n_cpy;

	size = 0;
	n_cpy = n;
	if (n == -2147483648)
	{
		size = 11;
		n_cpy = 0;
	}
	else if (n_cpy < 0)
	{
		n_cpy *= -1;
		size = 1;
	}
	else if (n == 0)
		size = 1;
	while (n_cpy != 0)
	{
		n_cpy /= 10;
		size++;
	}
	ft_putnbr_fd(n, 1);
	return (size);
}
