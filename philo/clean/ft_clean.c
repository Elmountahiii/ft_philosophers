/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:54:25 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/28 21:47:42 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_clean_mutexes(t_general_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(info->exit_lock);
	pthread_mutex_destroy(info->is_dead_lock);
	pthread_mutex_destroy(info->print_lock);
	pthread_mutex_destroy(info->simulation_end_lock);
	free(info->exit_lock);
	free(info->is_dead_lock);
	free(info->print_lock);
	free(info->simulation_end_lock);
	while (i < info->philo_num)
	{
		pthread_mutex_destroy(info->philosophers[i].last_meal_lock);
		pthread_mutex_destroy(info->philosophers[i].left_fork);
		pthread_mutex_destroy(info->philosophers[i].right_fork);
		pthread_mutex_destroy(info->philosophers[i].meal_count_lock);
		free(info->philosophers[i].last_meal_lock);
		free(info->philosophers[i].meal_count_lock);
		i++;
	}
	free(info->forks);
}

void	ft_clean(t_general_info *info)
{
	ft_clean_mutexes(info);
	free(info->philosophers);
	free(info);
}
