/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:39:29 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/30 17:04:19 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_monitoring(t_general_info *info)
{
	int		i;

	i = 0;
	while (ft_check_monitor_exit(info))
	{
		// i = 0;
		// while (i < info->philo_num)
		// {
		// 	if (ft_check_death(info, i))
		// 	{
		// 		// pthread_mutex_lock(info->is_dead_lock);
		// 		pthread_mutex_lock(info->all_lock);
		// 		info->is_dead = true;
		// 		info->exit = true;
		// 		// pthread_mutex_unlock(info->is_dead_lock);
		// 		pthread_mutex_unlock(info->all_lock);
		// 		ft_print_died(&info->philosophers[i]);
		// 		break ;
		// 	}
		// 	i ++;
		// }
		usleep(100);
	}
}
