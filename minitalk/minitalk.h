/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:18:39 by daypark           #+#    #+#             */
/*   Updated: 2021/06/25 16:58:58 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

/*
 *	server.c
 */
void	sig_handler(int sig);

/*
 * client.c
 */


/*
 * utils.c
 */
int		ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
int		ft_atoi(char *s);

#endif
