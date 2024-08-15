/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:38:06 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 21:59:14 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_check_death(t_general_info *info, int index)
{
	size_t	time_since;

	time_since = 0;
	pthread_mutex_lock(info->philosophers[index].meal_count_lock);
	return (0);
}
