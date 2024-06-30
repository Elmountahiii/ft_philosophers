/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:38:06 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/30 12:31:34 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_check_death(t_general_info *info, int index)
{
	// size_t	time_since;

	// time_since = 0;
	// pthread_mutex_lock(info->philosophers[index].meal_count_lock);
	// if (info->philosophers[index].meal_count != info->meal_target)
	// {
	// 	pthread_mutex_lock(info->philosophers[index].last_meal_lock);
	// 	time_since = ft_get_time() - info->philosophers[index].last_meal_time;
	// 	if (time_since > info->time_2_die)
	// 	{
	// 		pthread_mutex_unlock(info->philosophers[index].meal_count_lock);
	// 		pthread_mutex_unlock(info->philosophers[index].last_meal_lock);
	// 		return (1);
	// 	}
	// 	pthread_mutex_unlock(info->philosophers[index].last_meal_lock);
	// }
	// pthread_mutex_unlock(info->philosophers[index].meal_count_lock);
	size_t	time_since;

	time_since = 0;
	pthread_mutex_lock(info->philosophers[index].general_info->all_lock);
	if (info->philosophers[index].meal_count != info->meal_target)
	{
		//pthread_mutex_lock(info->philosophers[index].last_meal_lock);
		time_since = ft_get_time() - info->philosophers[index].last_meal_time;
		if (time_since > info->time_2_die)
		{
			// pthread_mutex_unlock(info->philosophers[index].meal_count_lock);
			// pthread_mutex_unlock(info->philosophers[index].last_meal_lock);
			pthread_mutex_unlock(info->philosophers[index].general_info->all_lock);
			return (1);
		}
		//pthread_mutex_unlock(info->philosophers[index].last_meal_lock);
	}
	//pthread_mutex_unlock(info->philosophers[index].meal_count_lock);
	pthread_mutex_unlock(info->philosophers[index].general_info->all_lock);
	return (0);
}
