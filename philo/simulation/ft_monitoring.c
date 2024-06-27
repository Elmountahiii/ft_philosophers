/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:39:29 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/27 13:11:01 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_monitoring(t_general_info *info)
{
	int		i;
	size_t	time_since;

	i = 0;
	time_since = 0; 
	while (!info->exit)
	{
		i = 0;
		while (i < info->philo_num)
		{
			if (ft_check_death(info, i))
			{
				pthread_mutex_lock(info->is_dead_lock);
				info->is_dead = true;
				info->exit = true;
				pthread_mutex_unlock(info->is_dead_lock);
				ft_print_died(&info->philosophers[i]);
				break ;
			}
			i ++;
		}
		ft_check_monitor_exit(info);
	}
}
