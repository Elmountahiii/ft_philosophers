/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_philo_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:06:42 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 22:29:37 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_check_philo_exit(t_philosopher *philo)
{
	pthread_mutex_lock(philo->general_info->is_dead_lock);
	if (philo->general_info->is_dead
		|| philo->meal_count == philo->general_info->meal_target)
	{
		pthread_mutex_unlock(philo->general_info->is_dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->general_info->is_dead_lock);
	return (0);
}
