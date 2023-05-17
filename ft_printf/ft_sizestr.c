/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:04:27 by abeaudui          #+#    #+#             */
/*   Updated: 2023/05/17 16:04:30 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sizestr(char *s)
{
	int		i;
	int		size;
	char	c;

	i = 0;
	size = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			c = s[i];
			write(1, &c, 1);
			size++;
			i++;
		}
	}
	else
	{
		ft_putstr("(null)");
		size += 6;
	}
	return (size);
}
