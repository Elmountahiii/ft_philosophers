/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:40:01 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/01 14:45:59 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_read_dead(t_general_info *info)
{
	int	i;

	pthread_mutex_lock(info->check_lock);
	i = info->is_dead;
	pthread_mutex_unlock(info->check_lock);
	return (i);
}

int	ft_read_exit(t_general_info *info)
{
	int	i;

	pthread_mutex_lock(info->check_lock);
	i = info->exit;
	pthread_mutex_unlock(info->check_lock);
	return (i);
}

int	ft_read_check(t_general_info *info)
{
	int	i;

	pthread_mutex_lock(info->check_lock);
	if (info->exit || info->is_dead)
		i = 1;
	else
	i = 0;
	pthread_mutex_unlock(info->check_lock);
	return (i);
}
