/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:48:03 by daypark           #+#    #+#             */
/*   Updated: 2021/10/24 16:16:43 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_phil *phil, int status)
{
	long long	ms;

	pthread_mutex_lock(&phil->data->print_mutex);
	ms = timestamp() - phil->data->start_time;
	if (!phil->data->phil_died && !phil->data->phil_eat_all)
	{
		if (status == FORKING)
			printf("%lldms\t%d has taken a fork\n", ms, phil->number);
		if (status == EATING)
			printf("%lldms\t%d is eating\n", ms, phil->number);
		if (status == SLEEPING)
			printf("%lldms\t%d is sleeping\n", ms, phil->number);
		if (status == THINKING)
			printf("%lldms\t%d is thinking\n", ms, phil->number);
		if (status == DIED)
			printf("%lldms\t%d died\n", ms, phil->number);
	}
	pthread_mutex_unlock(&phil->data->print_mutex);
}

int	print_error(t_data *data, int errorcode)
{
	if (errorcode == ARGC_ERROR)
	{
		putstr_fd("format: ./philo number_of_philosophers time_to_die ", 2);
		putstr_fd("time_to_eat time_to_sleep ", 2);
		putstr_fd("[number_of_times_each_philosopher_must_eat]\n", 2);
	}
	else if (errorcode == NUM_ERROR)
		putstr_fd("Check your arguments!\n", 2);
	else if (errorcode == ETC_ERROR)
		putstr_fd("Error!\n", 2);
	terminate(data, errorcode);
	return (0);
}

void	putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
}
