/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_mutexes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:03:37 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/01 14:47:18 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_clean_mutexes(t_general_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(info->print_lock);
	while (i < info->philo_num)
	{
		pthread_mutex_destroy(info->philosophers[i].left_fork);
		pthread_mutex_destroy(info->philosophers[i].right_fork);
		pthread_mutex_destroy(info->philosophers[i].last_meal_lock);		
		i++;
	}
}
