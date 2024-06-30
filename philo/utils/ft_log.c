/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:30:58 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/30 17:52:43 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_log(t_philosopher *philo, char *str)
{
	// pthread_mutex_lock(philo->general_info->is_dead_lock);
	// pthread_mutex_lock(philo->general_info->exit_lock);
	// if (!philo->general_info->is_dead && !philo->general_info->exit)
	// {
	// 	pthread_mutex_lock(philo->general_info->print_lock);
	// 	printf("%ld %d %s\n",
	// 		ft_get_time() - philo->general_info->simulation_start,
	// 		philo->id, str);
	// 	pthread_mutex_unlock(philo->general_info->print_lock);
	// }
	// pthread_mutex_unlock(philo->general_info->exit_lock);
	// pthread_mutex_unlock(philo->general_info->is_dead_lock);
	pthread_mutex_lock(philo->general_info->print_lock);
	printf("%ld %d %s\n",
		ft_get_time() - philo->general_info->simulation_start,
	 	philo->id, str);
	pthread_mutex_unlock(philo->general_info->print_lock);
		
}
