/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philosophers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:38:15 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/01 14:43:54 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	init(t_general_info *info, int i)
{
	info->philosophers[i].general_info = info;
	info->philosophers[i].id = i + 1;
	info->philosophers[i].right_fork = &info->forks[i];
	info->philosophers[i].left_fork = &info->forks[(i + 1) % info->philo_num];
	info->philosophers[i].meal_count = 0;
	info->philosophers[i].last_meal_time = ft_get_time();
}

int	ft_init_philosophers(t_general_info *info)
{
	int	i;

	i = 0;
	info->philosophers = malloc(sizeof(t_philosopher) * info->philo_num);
	if (!info->philosophers)
		return (1);
	while (i < info->philo_num)
	{
		info->philosophers[i].last_meal_lock = malloc(sizeof(pthread_mutex_lock));
		// check for last_meal_lock
		if (pthread_mutex_init(info->philosophers[i].last_meal_lock, NULL) != 0)
			return (1);
		init(info, i);
		i++;
	}
	return (0);
}
