/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:03:32 by abeaudui          #+#    #+#             */
/*   Updated: 2023/05/17 16:03:35 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_sizechar(char c);
int		ft_size_unsignedint(unsigned int n);
int		ft_sizestr(char *s);
int		ft_sizep(void);
int		ft_sizeint(int n);
int		ft_sizehexa(unsigned int n, char c);
void	ft_putstr(const char *s);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf(const char *s, ...);
int		ft_flags(va_list lst, char c);
int		ft_sizeptr(unsigned long long n);

#endif
