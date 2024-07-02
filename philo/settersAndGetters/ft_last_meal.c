/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_meal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:37:58 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/02 09:46:06 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_set_last_meal(t_philosopher *philo, size_t time)
{
	pthread_mutex_lock(philo->last_meal_lock);
	philo->last_meal_time = time;
	pthread_mutex_unlock(philo->last_meal_lock);
}

size_t	ft_get_last_meal(t_philosopher *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->last_meal_lock);
	time = philo->last_meal_time;
	pthread_mutex_unlock(philo->last_meal_lock);
	return (time);
}