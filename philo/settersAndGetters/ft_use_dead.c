/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_use_dead.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:21:26 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 22:11:41 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	ft_get_dead(t_general_info *info)
{
	bool	dead;

	pthread_mutex_lock(info->is_dead_lock);
	dead = info->is_dead;
	pthread_mutex_unlock(info->is_dead_lock);
	return (dead);
}

void	ft_set_dead(t_general_info *info, bool dead)
{
	pthread_mutex_lock(info->is_dead_lock);
	info->is_dead = dead;
	pthread_mutex_unlock(info->is_dead_lock);
}
