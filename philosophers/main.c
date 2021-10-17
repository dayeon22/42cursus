/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:26:30 by daypark           #+#    #+#             */
/*   Updated: 2021/10/17 18:11:30 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (arg_check(argc, argv, &data))
		return (0); //print_error();
	init_data(&data);
	data.start_time = timestamp();
	create_phils(&data); //실패시 print_error();
	while (!death_check(&data) && !eat_all(&data))
		usleep(5);
	terminate(&data);
}

void	terminate(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->phil_num)
		pthread_mutex_destroy(&data->fork[i++]);
//	스레드 언제 반환되는지(detach한것)
//	free(data->phil);
//	free(data->fork);
}

int	death_check(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->phil_num)
	{
		if (timestamp() - data->phil[i].last_eat > data->die_time)
		{
			print_status(&data->phil[i], DIED);
			return (1);
		}
	}
	return (0);
}

int	eat_all(t_data *data)
{
	int	i;

	i = -1;
	if (data->must_eat == -1)
		return (0);
	while (++i < data->phil_num)
	{
		if (data->phil[i].eat_cnt < data->must_eat)
			return (0);
	}
	return (1);
}

void	*act(void *arg)
{
	t_phil	*phil;

	phil = (t_phil *)arg;
	usleep(50);
	while (1)
	{
		if (phil->number % 2)
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
		}
		else
		{
			pthread_mutex_lock(&phil->data->fork[right(phil, FORK)]);
			print_status(phil, FORKING);
			pthread_mutex_lock(&phil->data->fork[left(phil, FORK)]);
			print_status(phil, FORKING);
			phil->last_eat = timestamp();
			print_status(phil, EATING);
			msleep(phil->data->eat_time);
			phil->eat_cnt++;
			pthread_mutex_unlock(&phil->data->fork[right(phil, FORK)]);
			pthread_mutex_unlock(&phil->data->fork[left(phil, FORK)]);
			print_status(phil, SLEEPING);
			msleep(phil->data->sleep_time);
		}
	}
	return (phil);
}

void	print_status(t_phil *phil, int status)
{
	long long	ms;

	ms = timestamp() - phil->data->start_time;
	phil->status = status;
	if (status == FORKING)
		printf("%lldms\t%d has taken a fork\n", ms, phil->number);
	else if (status == EATING)
		printf("%lldms\t%d is eating\n", ms, phil->number);
	else if (status == SLEEPING)
		printf("%lldms\t%d is sleeping\n", ms, phil->number);
	else if (status == THINKING)
		printf("%lldms\t%d is thinking\n", ms, phil->number);
	else if (status == DIED)
		printf("%lldms\t%d died\n", ms, phil->number);
}

int	create_phils(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->phil_num)
	{
		data->phil[i].last_eat = timestamp();
		pthread_create(&data->phil[i].pthread, NULL, act, &data->phil[i]); //실패시
		pthread_detach(data->phil[i].pthread);
	}
	return (0);
}

int	arg_check(int argc, char **argv, t_data *data)
{
	// int값 벗어남, 시간인데 음수 인자로 들어옴, 철학자수 1명이하 등등 처리하기
	if (argc < 5 || 6 < argc)
		return (1);
	data->phil_num = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->must_eat = -1;
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	data->phil = (t_phil *)malloc(sizeof(t_phil) * data->phil_num);
	data->fork = \
		(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->phil_num);
	if (!data->phil || !data->fork)
		return (1);
	return (0);
}

void	init_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->phil_num)
		pthread_mutex_init(&data->fork[i++], NULL);
	i = -1;
	while (++i < data->phil_num)
	{
		data->phil[i].number = i + 1;
		data->phil[i].status = THINKING;
		data->phil[i].eat_cnt = 0;
		data->phil[i].data = data;
	}
}
