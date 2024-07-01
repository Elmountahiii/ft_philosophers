/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mutexes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:53:57 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/01 14:53:01 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_init_mutexes(t_general_info *info)
{
	int	i;

	i = 0;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->philo_num);
	info->check_lock = malloc(sizeof(pthread_mutex_t));
	info->print_lock = malloc(sizeof(pthread_mutex_t));
	info->simulation_end_lock = malloc(sizeof(pthread_mutex_t));
	if (!info->forks || !info->check_lock || !info->print_lock)
		return (1);
	while (i < info->philo_num)
	{
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
			return (1);
		i ++;
	}
	if (pthread_mutex_init(info->print_lock, NULL) != 0
		|| pthread_mutex_init(info->check_lock, NULL) != 0
		|| pthread_mutex_init(info->simulation_end_lock, NULL) != 0)
		return (1);
	
	return (0);
}
