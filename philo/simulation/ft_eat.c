/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:46:25 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/30 17:21:56 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_eat(t_philosopher *philo)
{
	// pthread_mutex_lock(philo->meal_count_lock);
	// philo->last_meal_time = ft_get_time();
	// pthread_mutex_unlock(philo->meal_count_lock);
	ft_log(philo, "is eating");
	philo->meal_count++;
	ft_sleep(philo->general_info->time_2_eat);
	if (philo->meal_count == philo->general_info->meal_target)
	{
		pthread_mutex_lock(philo->general_info->simulation_end_lock);
		philo->general_info->simulation_end ++;
		pthread_mutex_unlock(philo->general_info->simulation_end_lock);	
	}
}
