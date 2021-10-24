/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:26:30 by daypark           #+#    #+#             */
/*   Updated: 2021/10/24 14:51:00 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	int		errorcode;

	errorcode = arg_check(argc, argv, &data);
	if (errorcode)
		return (print_error(&data, errorcode));
	init_data(&data);
	data.start_time = timestamp();
	errorcode = create_phils(&data);
	if (errorcode)
		return (print_error(&data, errorcode));
	while (!death_check(&data) && !eat_all(&data))
		usleep(100);
	terminate(&data, 0);
	return (0);
}

void	*act(void *arg)
{
	t_phil	*phil;

	phil = (t_phil *)arg;
	while (1)
	{
		pthread_mutex_lock(&phil->data->fork[left(phil, FORK)]);
		print_status(phil, FORKING);
		pthread_mutex_lock(&phil->data->fork[right(phil, FORK)]);
		print_status(phil, FORKING);
		phil->last_eat = timestamp();
		print_status(phil, EATING);
		msleep(phil->data->eat_time);
		phil->eat_cnt++;
		pthread_mutex_unlock(&phil->data->fork[left(phil, FORK)]);
		pthread_mutex_unlock(&phil->data->fork[right(phil, FORK)]);
		print_status(phil, SLEEPING);
		msleep(phil->data->sleep_time);
		print_status(phil, THINKING);
		usleep(100);
	}
	return (phil);
}

int	create_phils(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->phil_num)
	{
		usleep(100);
		data->phil[i].last_eat = timestamp();
		if (pthread_create(&data->phil[i].pthread, NULL, act, &data->phil[i]))
			return (ETC_ERROR);
		if (pthread_detach(data->phil[i].pthread))
			return (ETC_ERROR);
	}
	return (0);
}

int	arg_check(int argc, char **argv, t_data *data)
{
	if (argc < 5 || 6 < argc)
		return (ARGC_ERROR);
	if (check(argv[1]) || check(argv[2]) || check(argv[3]) || check(argv[4]))
		return (NUM_ERROR);
	data->phil_num = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
	{
		data->must_eat = ft_atoi(argv[5]);
		if (check(argv[5]) || data->must_eat < 1)
			return (NUM_ERROR);
	}
	else
		data->must_eat = -1;
	if (data->phil_num < 1 || data->die_time < 1 || \
			data->eat_time < 0 || data->sleep_time < 0)
		return (NUM_ERROR);
	data->phil = (t_phil *)malloc(sizeof(t_phil) * data->phil_num);
	data->fork = \
		(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->phil_num);
	if (!data->phil || !data->fork)
		return (ETC_ERROR);
	return (0);
}

void	init_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->phil_num)
		pthread_mutex_init(&data->fork[i++], NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	i = -1;
	while (++i < data->phil_num)
	{
		data->phil[i].number = i + 1;
		data->phil[i].eat_cnt = 0;
		data->phil[i].data = data;
		data->phil[i].last_eat = data->start_time;
		data->phil_died = 0;
		data->phil_eat_all = 0;
	}
}
