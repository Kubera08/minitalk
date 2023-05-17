/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:04:41 by abeaudui          #+#    #+#             */
/*   Updated: 2023/05/17 16:11:30 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_mess[5000000];

void	ft_reverse(int *i, char *byte, int *start, siginfo_t *siginfo)
{
	int	check_kill;

	check_kill = 1;
	g_mess[*i] = *byte;
	*byte = 0;
	if (g_mess[*i] == '\0')
	{
		ft_printf("%s\n", g_mess);
		*i = 0;
		*start = 0;
		check_kill = kill(siginfo->si_pid, SIGUSR2);
		signal_error(check_kill);
		return ;
	}
	(*i)++;
}

void	ft_handle_signal(int signum, siginfo_t *siginfo, void *context)
{
	static char	byte;
	static int	bit_received;
	static int	i;
	static int	start;

	(void)context;
	if (start == 1)
	{
		if (signum == SIGUSR2)
			byte |= (1 << bit_received);
		bit_received++;
		if (bit_received == 8)
		{
			bit_received = 0;
			ft_reverse(&i, &byte, &start, siginfo);
		}
		signal_error(kill(siginfo->si_pid, SIGUSR1));
	}
	else
	{
		start = 1;
		signal_error(kill(siginfo->si_pid, SIGUSR1));
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc > 1)
		ft_printf("Too many arguments\n");
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = ft_handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID : %d\n", getpid());
	while (1)
		pause();
	return (0);
}
