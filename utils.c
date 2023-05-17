/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:07:51 by mudoh             #+#    #+#             */
/*   Updated: 2023/05/17 15:11:18 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_error(int check_kill)
{
	if (check_kill == -1)
	{
		ft_printf("Echec");
		exit(1);
	}
}

void	ft_checkpid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!(pid[i] >= '0' && pid[i] <= '9'))
		{
			ft_printf(ROUGE "bad PID" NORMAL);
			exit(1);
		}
		i++;
	}
}

int	ft_atoi(const char *pid)
{
	int	number;
	int	i;

	i = 0;
	number = 0;
	if (pid[i] >= '0' && pid[i] <= '9')
	{
		while (pid[i])
		{
			number = (pid[i] - '0') + (number * 10);
			i++;
		}
		ft_printf(JAUNE "%d\n" NORMAL, number);
		return (number);
	}
	else
		ft_printf(JAUNE "wrong PID \n" NORMAL);
	exit(1);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
