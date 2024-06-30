/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:38:06 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/30 23:12:21 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_check_death(t_general_info *info, int index)
{
	size_t	time_since;

	time_since = 0;
	pthread_mutex_lock(info->philosophers[index].last_meal_lock);
	
		time_since = ft_get_time() - info->philosophers[index].last_meal_time;
		if (time_since > info->time_2_die)
		{
			pthread_mutex_unlock(info->philosophers[index].last_meal_lock);
			return (1);
		}
		pthread_mutex_unlock(info->philosophers[index].last_meal_lock);	
	return (0);
}
