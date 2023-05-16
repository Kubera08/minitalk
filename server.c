/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:32:12 by mudoh             #+#    #+#             */
/*   Updated: 2023/05/16 16:47:29 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_mess[5000000]; //le stockage du message

void	ft_reverse(int *i, char *byte, int *start, siginfo_t *siginfo) //fonction pour afficher le message
{
	int	check_kill;

	check_kill = 1;
	g_mess[*i] = *byte;// le charactere qu'on met dans la string
	*byte = 0;
	if (g_mess[*i] == '\0')//si on est a la fin de la string on l'affiche
	{
		ft_printf("%s\n", g_mess);//affichage du message
		*i = 0;
		*start = 0;
		check_kill = kill(siginfo->si_pid, SIGUSR2);//on envoie un signal (bonus) apres avoir affiche le message
		signal_error(check_kill);//on verifie si le signal s'est bien envoye
		return ;
	}
	(*i)++; // on avance dans la phrase
}

void	ft_handle_signal(int signum, siginfo_t *siginfo, void *context) //fonction pour verifier les bits recus et les changer en char
{
	static char	byte;
	static int	bit_received;
	static int	i;
	static int	start;

	(void)context; //pour eviter un warning a la compilation
	if (start == 1) //ca veut dire que la reception du message est en cours
	{
		if (signum == SIGUSR2) //un bit 1 a ete recu 
			byte |= (1 << bit_received); // on va remplir avec un 1 et decaler bit_receveid fois ( = le bit ou on est arrive )
		bit_received++;//on passe au bit d'apres
		if (bit_received == 8)  //on est arrive a la fin de la phrase recue
		{
			bit_received = 0; //on remet a 0 pour le prochain appel
			ft_reverse(&i, &byte, &start, siginfo); //on va afficher la phrase
		}
		signal_error(kill(siginfo->si_pid, SIGUSR1));//on demande la reception du prochain bit
	}
	else
	{
		start = 1;
		signal_error(kill(siginfo->si_pid, SIGUSR1));
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa; // 

	(void)argv;
	if (argc > 1)
		ft_printf(VIOLET "Too much argument!\n" NORMAL);
	sigemptyset(&sa.sa_mask); //on vide le sa_mask p -> pas de signaux parasites entre les appels
	sa.sa_sigaction = ft_handle_signal; // sigaction sert a modifier l'action d'un signal intercepte -> c'est avec handle_signal qu'on modifie
	sa.sa_flags = SA_SIGINFO ; //sa_flags spécifie un ensemble d'attributs qui modifient le comportement du signal -> SIGINFO nous donne des infos sur le signal
	sigaction(SIGUSR1, &sa, NULL); 
	sigaction(SIGUSR2, &sa, NULL); 
	ft_printf(JAUNE "PID : %d\n" NORMAL, getpid());
	while (1)
		pause(); // le programme se reveillera des qu'on recevra un signal et appellera la fonction ft_handle signal
	return (0);
}
