/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mutexes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:53:57 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/29 13:33:49 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_init_mutexes(t_general_info *info)
{
	int	i;

	i = 0;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->philo_num);
	info->print_lock = malloc(sizeof(pthread_mutex_t));
	info->is_dead_lock = malloc(sizeof(pthread_mutex_t));
	info->simulation_end_lock = malloc(sizeof(pthread_mutex_t));
	info->exit_lock = malloc(sizeof(pthread_mutex_t));
	if (!info->forks || !info->print_lock || !info->is_dead_lock
		|| !info->simulation_end_lock || !info->exit_lock)
		return (1);
	while (i < info->philo_num)
	{
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
			return (1);
		i ++;
	}
	if (pthread_mutex_init(info->print_lock, NULL) != 0
		|| pthread_mutex_init(info->is_dead_lock, NULL) != 0
		|| pthread_mutex_init(info->simulation_end_lock, NULL) != 0
		|| pthread_mutex_init(info->exit_lock, NULL) != 0)
		return (1);
	return (0);
}
