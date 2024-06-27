/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:15:00 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/27 14:46:50 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_free(t_general_info *info)
{
	// int	i;

	// i = 0;
	info->print_lock= NULL;
	free(info->print_lock);
	// free(info->is_dead_lock);
	// free(info->simulation_end_lock);
	// free(info->exit_lock);
	// while (i < info->philo_num)
	// {
	// 	free(info->philosophers[i].meal_count_lock);
	// 	free(info->philosophers[i].last_meal_lock);
	// 	i ++;
	// }
	// free(info->forks);
	// free(info->philosophers);
	// free(info);
}
