/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dead_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:16:49 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/02 10:20:10 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	ft_get_exit(t_general_info *info)
{
	bool exit;
	pthread_mutex_lock(info->exit_lock);
	exit = info->exit;
	pthread_mutex_unlock(info->exit_lock);
	return (exit);
}

void	ft_set_exit(t_general_info *info, bool exit)
{
	pthread_mutex_lock(info->exit_lock);
	info->exit = exit;
	pthread_mutex_unlock(info->exit_lock);
}
