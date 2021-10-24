/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:49:02 by daypark           #+#    #+#             */
/*   Updated: 2021/10/24 14:50:34 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	left(t_phil *phil, int type)
{
	if (type == FORK)
		return (phil->number - 1);
	else
		return ((phil->number) % phil->data->phil_num);
}

int	right(t_phil *phil, int type)
{
	type = 0;
	return ((phil->number + phil->data->phil_num) % phil->data->phil_num);
}

int	death_check(t_data *data)
{
	int			i;
	long long	current_time;

	i = -1;
	current_time = timestamp();
	while (++i < data->phil_num)
	{
		if (current_time - data->phil[i].last_eat >= data->die_time)
		{
			print_status(&data->phil[i], DIED);
			data->phil_died = 1;
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
	data->phil_eat_all = 1;
	return (1);
}

void	terminate(t_data *data, int errorcode)
{
	int	i;

	i = -1;
	if (errorcode == ETC_ERROR || errorcode == 0)
	{
		while (++i < data->phil_num)
		{
			usleep(100);
			pthread_mutex_destroy(&data->fork[i]);
		}
		pthread_mutex_destroy(&data->print_mutex);
		free(data->phil);
		free(data->fork);
	}
}
