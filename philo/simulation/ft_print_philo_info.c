/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_philo_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:43:47 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 22:05:45 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_print_philo_info(t_philosopher *philo)
{
	pthread_mutex_lock(philo->general_info->print_lock);
	printf("philo id : %d  \n", philo->id);
	pthread_mutex_unlock(philo->general_info->print_lock);
}
