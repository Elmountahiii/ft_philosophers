/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:46:25 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/01 10:04:11 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_eat(t_philosopher *philo)
{
	if (ft_log(philo, "is eating"))
		return (1);
	pthread_mutex_lock(philo->last_meal_lock);
	philo->last_meal_time = ft_get_time();
	pthread_mutex_unlock(philo->last_meal_lock);
	if (ft_sleep(philo, philo->general_info->time_2_eat))
		return (1);
	philo->meal_count++;
	if (philo->meal_count == philo->general_info->meal_target)
	{
		pthread_mutex_lock(philo->general_info->check_lock);
		philo->general_info->simulation_end ++;
		pthread_mutex_unlock(philo->general_info->check_lock);	
	}
	return (0);
}
