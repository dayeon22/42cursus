/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:57:07 by daypark           #+#    #+#             */
/*   Updated: 2021/10/13 00:42:37 by daypark          ###   ########.fr       */
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
		phil->last_eat = timestamp();
		usleep(phil->data->eat_time * 1000);
		phil->eat_cnt++;
		pthread_mutex_unlock(&phil->data->fork[left_fork(phil)]);
		pthread_mutex_unlock(&phil->data->fork[right_fork(phil)]);
		printf("%lld %d is sleeping\n", timestamp(), phil->number);
		usleep(phil->data->sleep_time * 1000);
	}
	return (phil);
}

int	eat_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->phil_num)
	{
		if (data->phil[i].eat_cnt < data->must_eat)
			return (0);
	}
	return (1);
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
		data.phil[i].status = ALIVE;
		data.phil[i].eat_cnt = 0;
		data.phil[i].last_eat = timestamp();
		pthread_create(&data.phil[i].pthread, NULL, act, &data.phil[i]); //실패시
		pthread_detach(data.phil[i].pthread);
	}
//	i = 0;
//	while (i < data.phil_num)
//		pthread_(data.phil[i++].pthread, NULL);

	int	die_flag = 0;

	while (!die_flag && !eat_all(&data))
	{
		i = -1;
		while (++i < data.phil_num)
		{
			if (timestamp() - data.phil[i].last_eat > data.die_time)
			{
				die_flag = 1;
				break ;
			}
		}
		usleep(50);
	}

	i = 0;
	while (i < data.phil_num)
		pthread_mutex_destroy(&data.fork[i++]);
}
