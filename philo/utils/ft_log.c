/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:30:58 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/25 14:52:13 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_log(t_philosopher *philo, char *str)
{
	pthread_mutex_lock(philo->general_info->print_lock);
	if (ft_get_dead(philo->general_info))
	{
		pthread_mutex_unlock(philo->general_info->print_lock);
		return (1);
	}
	printf("%ld %d %s\n",
		ft_get_time() - philo->general_info->simulation_start, philo->id, str);
	pthread_mutex_unlock(philo->general_info->print_lock);
	return (0);
}
