/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:17:59 by mudoh             #+#    #+#             */
/*   Updated: 2023/05/16 17:41:00 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// chaque char = 1 octets = 8 bits. chaque signal = 1 bit

#include "minitalk.h"

char	g_mess[5000000]; //stockage du message


void	handle_signal(int signal, siginfo_t *siginfo, void *context)//on traite le signal recu
{
	static int	nb_bit;//bits recus
	static int	i; //index du message

	(void)context;
	if (signal == SIGUSR1)//un bit du message est transmis
	{
		if (g_mess[i] & 1 << nb_bit)//si le bit est a 1 dans le message
			signal_error(kill(siginfo->si_pid, SIGUSR2)); //on envoie un signal SIGUSR2 pour indiquer que le bit a bien ete recu
		else
			signal_error(kill(siginfo->si_pid, SIGUSR1)); //sinon on envoie SIGUSR1 pour indiquer une erreur de reception
		nb_bit++;
		if (nb_bit == 8)//8 bits dans un octet
		{
			i++; //on passe au caractere suivant
			nb_bit = 0;
		}
		printf("%d/n", siginfo->si_pid);
	}
	else
		exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	struct sigaction sa; //gestion des signaux

	if (argc == 3)
	{
		ft_checkpid(argv[1]); //on check si le PID est bon ou pas
		sigemptyset(&sa.sa_mask);//on vide le mask pr etre sur qu il y a pas de signaux parasites
		sa.sa_sigaction = handle_signal;// fonction a utiliser pour gerer le signal
		sa.sa_flags = SA_SIGINFO;//on utiliser siginfo_t plutot que void pour recevoir + d'infos supplementaires sur le signal
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		ft_strcpy(g_mess, argv[2]);//on met le message dans g_mess
		signal_error(kill(ft_atoi(argv[1]), SIGUSR1)); //on envoie un signal SIGUSR1 pour indiquer qu'on peut commencer a transmettre le message
		while (1)
			pause();
	}
	else
	{
		ft_printf(ROUGE "Il faut 3 arguments !" NORMAL);
		exit(EXIT_FAILURE);
	}
	return (0);
}