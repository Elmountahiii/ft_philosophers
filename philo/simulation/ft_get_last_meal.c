/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last_meal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:08:10 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/01 14:45:16 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

size_t	ft_get_last_meal(t_philosopher *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->last_meal_lock);
	time = philo->last_meal_time;
	pthread_mutex_unlock(philo->last_meal_lock);
	return (time);
}
