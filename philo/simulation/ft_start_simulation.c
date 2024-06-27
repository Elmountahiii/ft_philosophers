/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:18:39 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/25 12:52:21 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_start_simulation(t_general_info *info)
{
	int i;

	i = 0;
	info->simulation_start = ft_get_time();
	while (i < info->philo_num)
	{
		 pthread_create(&info->philosophers[i].thread, NULL, ft_simulation, &info->philosophers[i]);
		i++;
	}
	ft_monitoring(info);
	
}
