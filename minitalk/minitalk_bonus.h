/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:18:39 by daypark           #+#    #+#             */
/*   Updated: 2021/07/01 16:45:26 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

#include <unistd.h>
#include <signal.h>

typedef struct		s_info
{
	unsigned char	c;
	int				shift;
}					t_info;

void	sig_handler(int sig);

int		transmission(char c, int send_pid);

void	ft_putchar_fd(char c, int fd);
int		ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(char *s);
void	ft_putnbr_fd(int n, int fd);

#endif
