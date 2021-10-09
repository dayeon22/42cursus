/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:57:07 by daypark           #+#    #+#             */
/*   Updated: 2021/10/09 19:51:46 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*act(void *arg)
{
	t_phil			*phil;

	phil = (t_phil *)arg;
	while (1)
	{
		pthread_mutex_lock(&phil->data->fork[left_fork(phil)]);
		printf("%lld %d has taken a fork\n", timestamp(), phil->number);

		pthread_mutex_lock(&phil->data->fork[right_fork(phil)]);
		printf("%lld %d has taken a fork\n", timestamp(), phil->number);
		printf("%lld %d is eating\n", timestamp(), phil->number);
		usleep(phil->data->eat_time * 1000);
		pthread_mutex_unlock(&phil->data->fork[left_fork(phil)]);
		pthread_mutex_unlock(&phil->data->fork[right_fork(phil)]);
		printf("%lld %d is sleeping\n", timestamp(), phil->number);
		usleep(phil->data->sleep_time * 1000);
	}
	return (phil);
}

int	main(int argc, char *argv[])
{
	t_data		data;
	int			i;

	if (argc < 5 || 6 < argc)
		return (0);
	data.phil_num = ft_atoi(argv[1]);
	data.die_time = ft_atoi(argv[2]);
	data.eat_time = ft_atoi(argv[3]);
	data.sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		data.must_eat = ft_atoi(argv[5]);
	data.phil = (t_phil *)malloc(sizeof(t_phil) * data.phil_num); //실패시
	data.fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data.phil_num);// 실패시

	i = 0;
	while (i < data.phil_num)
		pthread_mutex_init(&data.fork[i++], NULL);
	i = -1;
	while (++i < data.phil_num)
	{
		data.phil[i].data = &data;
		data.phil[i].number = i + 1;
		pthread_create(&data.phil[i].pthread, NULL, act, &data.phil[i]); //실패시
	}
	i = 0;
	while (i < data.phil_num)
		pthread_join(data.phil[i++].pthread, NULL);

	i = 0;
	while (i < data.phil_num)
		pthread_mutex_destroy(&data.fork[i++]);
}
