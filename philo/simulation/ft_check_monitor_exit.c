/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_monitor_exit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:55:45 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/30 23:09:12 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_check_monitor_exit(t_general_info *info)
{
	pthread_mutex_lock(info->check_lock);
	if (info->exit)
	{
			pthread_mutex_unlock(info->check_lock);
	return (0);
	}
	if (info->simulation_end == info->philo_num )
	{
		// pthread_mutex_lock(info->exit_lock);
		info->exit = true;
		pthread_mutex_unlock(info->check_lock);
		return (0);
	}
	pthread_mutex_unlock(info->check_lock);
	return (1);
}
