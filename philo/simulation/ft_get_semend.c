/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_semend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:52:15 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/01 14:45:24 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_get_semend(t_general_info *info)
{
	int i;
	pthread_mutex_lock(info->simulation_end_lock);
	i = info->simulation_end;
	pthread_mutex_unlock(info->simulation_end_lock);
	return (i);
}