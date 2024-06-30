/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_philo_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:06:42 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/30 22:53:27 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_check_philo_exit(t_philosopher *philo)
{
	pthread_mutex_lock(philo->general_info->check_lock);
	// pthread_mutex_lock(philo->general_info->exit_lock);
	if (philo->general_info->is_dead || philo->general_info->exit)
	{
		pthread_mutex_unlock(philo->general_info->check_lock);
		// pthread_mutex_unlock(philo->general_info->exit_lock);
		return (1);
	}
	// pthread_mutex_unlock(philo->general_info->is_dead_lock);
	pthread_mutex_unlock(philo->general_info->check_lock);
	return (0);
}
