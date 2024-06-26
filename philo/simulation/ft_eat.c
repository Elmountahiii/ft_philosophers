/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:46:25 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/01 14:54:46 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_eat(t_philosopher *philo)
{
	ft_log(philo, "is eating");
	ft_set_last_meal(philo,ft_get_time());
	ft_sleep(philo->general_info->time_2_eat);
	philo->meal_count++;
	if (philo->meal_count == philo->general_info->meal_target)
		ft_set_simend(philo->general_info,ft_get_semend(philo->general_info)+1);
}
