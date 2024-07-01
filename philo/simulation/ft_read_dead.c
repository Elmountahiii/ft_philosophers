/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_dead.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:30:19 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/01 09:35:13 by yel-moun         ###   ########.fr       */
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
