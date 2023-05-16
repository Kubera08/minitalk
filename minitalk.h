/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:32:07 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/11 12:59:10 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <ucontext.h>
# include "./ft_printf/ft_printf.h"
# include <signal.h>
# include <sys/types.h>
# define NORMAL "\033[00m"
# define NORMALBK "\33[49m"
# define SOULIGNE "\033[04m"
# define NOIR "\033[00;30m"
# define ROUGE "\033[01;31m"
# define VERT "\033[01;32m"
# define JAUNE "\033[01;33m"
# define BLEU "\033[01;34m"
# define VIOLET "\033[03;35m"
# define CYAN "\033[00;36m"
# define BLANC "\033[00;37m"

void	ft_checkpid(char *pid);
void	signal_error(int check_kill);
int		ft_atoi(const char *pid);
char	*ft_strcpy(char *dst, const char *src);
#endif