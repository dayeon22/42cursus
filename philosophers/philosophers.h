/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:00:27 by daypark           #+#    #+#             */
/*   Updated: 2021/10/24 13:15:47 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define DIED -1
# define FORKING 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define REACHED 4

# define FORK 4
# define PHIL 5

# define ARGC_ERROR 1
# define NUM_ERROR 2
# define ETC_ERROR 3

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_phil
{
	int				number;
	pthread_t		pthread;
	int				eat_cnt;
	long long		last_eat;
	struct s_data	*data;
}				t_phil;

typedef struct s_data
{
	int				phil_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	long long		start_time;
	int				phil_died;
	int				phil_eat_all;
	t_phil			*phil;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_mutex;
}				t_data;

/*
 * main.c
 */
int			arg_check(int argc, char **argv, t_data *data);
void		init_data(t_data *data);
int			create_phils(t_data *data);
void		*act(void *arg);
void		print_status(t_phil *phil, int status);
void		terminate(t_data *data, int errorcode);
int			death_check(t_data *data);
int			eat_all(t_data *data);

/*
 * utils.c
 */
int			ft_strcmp(const char *s1, const char *s2);
int			ft_atoi(const char *str);
long long	timestamp(void);
int			left(t_phil *phil, int type);
int			right(t_phil *phil, int type);
void		msleep(int ms);
int			check(char *str);
int			print_error(t_data *data, int errorcode);
void		putstr_fd(char *str, int fd);

#endif
