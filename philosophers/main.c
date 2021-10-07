/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:57:07 by daypark           #+#    #+#             */
/*   Updated: 2021/10/07 21:46:51 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	mutex;

void	*eat(void *arg)
{
	t_data			*data;
	struct timeval	time;

	data = (t_data *)arg;

	pthread_mutex_lock(&mutex);
	gettimeofday(&time, NULL);
	printf("%d %d is eating\n", time.tv_usec * 1000, data->phil->number);
	usleep(data->eat_time * 1000);
	gettimeofday(&time, NULL);
	printf("%d %d is sleeping\n", time.tv_usec * 1000, data->phil->number);
	pthread_mutex_unlock(&mutex);

	return data;
}

int	main(int argc, char *argv[])
{
	t_data		data;
	int			i;

	if (argc < 5 || argc > 6)
		return (0);
	data.phil_num = ft_atoi(argv[1]);
	data.die_time = ft_atoi(argv[2]);
	data.eat_time = ft_atoi(argv[3]);
	data.sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		data.must_eat = ft_atoi(argv[5]);
	data.phil = (t_phil *)malloc(sizeof(t_phil) * data.phil_num); //실패시

	pthread_mutex_init(&mutex, NULL);
	i = 0;
	while (i < data.phil_num)
		pthread_create(&data.phil[i++].pthread, NULL, eat, &data);
	i = 0;
	while (i < data.phil_num)
		pthread_join(data.phil[i++].pthread, NULL);

	pthread_mutex_destroy(&mutex);
}
