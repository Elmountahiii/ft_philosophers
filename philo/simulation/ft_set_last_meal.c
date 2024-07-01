/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_last_meal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:58:39 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/01 14:46:07 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_set_last_meal(t_philosopher *philo, size_t value)
{
	pthread_mutex_lock(philo->last_meal_lock);
	philo->last_meal_time = value;
	pthread_mutex_unlock(philo->last_meal_lock);
}
