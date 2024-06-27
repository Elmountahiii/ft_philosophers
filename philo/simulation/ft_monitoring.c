/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:39:29 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/27 11:27:38 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_monitoring(t_general_info *info)
{
	int i;
	size_t time_since;

	i = 0;
	time_since = 0; 
	while (!info->exit  )
	{
		i = 0;
		while (i < info->philo_num)
		{
			pthread_mutex_lock(info->philosophers[i].meal_count_lock);
			if (info->philosophers[i].meal_count != info->meal_target)
			{
				pthread_mutex_lock(info->philosophers[i].last_meal_lock);
				time_since = ft_get_time() - info->philosophers[i].last_meal_time;
				if (time_since > info->time_2_die)
				{
					pthread_mutex_lock(info->is_dead_lock);
					info->is_dead = true;
					info->exit = true;
					pthread_mutex_unlock(info->is_dead_lock);
					ft_print_died(&info->philosophers[i]);
					pthread_mutex_unlock(info->philosophers[i].last_meal_lock);
					break;
				}				
				pthread_mutex_unlock(info->philosophers[i].last_meal_lock);
			}
			pthread_mutex_unlock(info->philosophers[i].meal_count_lock);
			i ++;
		}
		pthread_mutex_lock(info->simulation_end_lock);
		if (info->simulation_end == info->philo_num)
			info->exit = true;
		pthread_mutex_unlock(info->simulation_end_lock);
	}
}
