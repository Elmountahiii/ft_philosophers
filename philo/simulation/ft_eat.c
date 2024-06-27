/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:46:25 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/27 13:12:03 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_eat(t_philosopher *philo)
{
	pthread_mutex_lock(philo->last_meal_lock);
	philo->last_meal_time = ft_get_time();
	pthread_mutex_unlock(philo->last_meal_lock);
	ft_log(philo, "is eating");
	ft_sleep(philo->general_info->time_2_eat);
	pthread_mutex_lock(philo->meal_count_lock);
	philo->meal_count++;
	pthread_mutex_unlock(philo->meal_count_lock);
}
