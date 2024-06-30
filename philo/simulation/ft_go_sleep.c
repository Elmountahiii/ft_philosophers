/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:35:27 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/30 23:09:46 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_go_sleep(t_philosopher *philo)
{
	ft_log(philo, "is sleeping");
	ft_sleep(philo->general_info->time_2_sleep);
	philo->meal_count++;
	if (philo->meal_count == philo->general_info->meal_target)
	{
		pthread_mutex_lock(philo->general_info->check_lock);
		philo->general_info->simulation_end ++;
		pthread_mutex_unlock(philo->general_info->check_lock);	
	}
}
