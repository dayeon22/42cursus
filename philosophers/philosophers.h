/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:00:27 by daypark           #+#    #+#             */
/*   Updated: 2021/10/05 16:49:26 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct	s_phil
{
	int			number;
	pthread_t	pthread;
}				t_phil;

typedef struct	s_data
{
	int		phil_num;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		must_eat;
	t_phil	*phil;
}				t_data;

/*
 * utils.c
 */
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);

#endif
