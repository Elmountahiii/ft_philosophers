/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:39:29 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 22:05:21 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_monitoring(t_general_info *info)
{
	int		i;
	size_t	time_since;

	i = 0;
	time_since = 0;
	while (!ft_get_exit(info))
	{
		i = 0;
		while (i < info->philo_num)
		{
			time_since
				= ft_get_time() - ft_get_last_meal(&info->philosophers[i]);
			if (time_since > info->time_2_die)
			{
				ft_set_dead(info, true);
				ft_set_exit(info, true);
				ft_print_died(&info->philosophers[i]);
				break ;
			}
			i ++;
		}
	}
}
