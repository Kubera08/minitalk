/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:03:11 by abeaudui          #+#    #+#             */
/*   Updated: 2023/05/17 16:03:25 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	int		size;
	va_list	lst;

	va_start(lst, s);
	i = -1;
	size = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == '%')
			size += ft_flags(lst, s[++i]);
		else
			size += ft_sizechar(s[i]);
	}
	va_end(lst);
	return (size);
}
