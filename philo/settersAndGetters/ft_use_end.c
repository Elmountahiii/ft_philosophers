/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_use_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 22:38:12 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/28 20:47:11 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_get_simulation_end(t_general_info *info)
{
	int	end;

	pthread_mutex_lock(info->simulation_end_lock);
	end = info->simulation_end;
	pthread_mutex_unlock(info->simulation_end_lock);
	return (end);
}

void	ft_set_simulation_end(t_general_info *info)
{
	pthread_mutex_lock(info->simulation_end_lock);
	info->simulation_end++;
	pthread_mutex_unlock(info->simulation_end_lock);
}
