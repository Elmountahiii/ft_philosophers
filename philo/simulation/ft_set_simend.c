/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_simend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:45:48 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/01 14:46:13 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_set_simend(t_general_info *info, int value)
{
	pthread_mutex_lock(info->simulation_end_lock);
	info->simulation_end = value;
	pthread_mutex_unlock(info->simulation_end_lock);
}