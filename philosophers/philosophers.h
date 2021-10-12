/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:00:27 by daypark           #+#    #+#             */
/*   Updated: 2021/10/12 23:31:00 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define DIED -1
# define ALIVE 1
//# define EATING 1
//# define SLEEPING 2
//# define THINKING 3

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

struct	s_data;

typedef struct	s_phil
{
	int				number;
	pthread_t		pthread;
	int				status;
	int				eat_cnt;
	long long		last_eat;
	struct s_data	*data;
}					t_phil;

typedef struct	s_data
{
	int				phil_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	t_phil			*phil;
	pthread_mutex_t	*fork;
}				t_data;

/*
 * utils.c
 */
int			ft_strcmp(const char *s1, const char *s2);
int			ft_atoi(const char *str);
long long	timestamp(void);
int			left_fork(t_phil *phil);
int			right_fork(t_phil *phil);

#endif