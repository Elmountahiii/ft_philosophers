/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edit_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:43:19 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/01 14:45:03 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_edit_check(t_general_info *info, bool value)
{
	pthread_mutex_lock(info->check_lock);
	info->is_dead = value;
	info->exit = value;
	pthread_mutex_unlock(info->check_lock);
}

void	ft_edit_exit(t_general_info *info, bool value)
{
	pthread_mutex_lock(info->check_lock);
	info->exit = value;
	pthread_mutex_unlock(info->check_lock);
}
void	ft_edit_dead(t_general_info *info, bool value)
{
	pthread_mutex_lock(info->check_lock);
	info->is_dead = value;
	pthread_mutex_unlock(info->check_lock);
}