/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_died.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:46:29 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/27 12:27:18 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_print_died(t_philosopher *philo)
{
	pthread_mutex_lock(philo->general_info->print_lock);
	printf("\033[0;31m%ld %d died \n\033[0m",
		ft_get_time() - philo->general_info->simulation_start,
		philo->id);
	pthread_mutex_unlock(philo->general_info->print_lock);
}
