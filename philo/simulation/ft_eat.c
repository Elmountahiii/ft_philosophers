/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:46:25 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 22:45:31 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_eat(t_philosopher *philo)
{
	if (ft_log(philo, "is eating"))
		return (1);
	ft_set_last_meal(philo, ft_get_time());
	if (ft_sleep(philo->general_info, philo->general_info->time_2_eat))
		return (1);
	pthread_mutex_lock(philo->meal_count_lock);
	philo->meal_count++;
	pthread_mutex_unlock(philo->meal_count_lock);
	if (philo->meal_count == philo->general_info->meal_target)
		ft_set_simulation_end(philo->general_info);
	return (0);
}
