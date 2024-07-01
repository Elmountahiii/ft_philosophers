/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:38:06 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/01 13:23:36 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_check_death(t_general_info *info, int index)
{
	size_t	time_since;

	time_since = 0;
	time_since = ft_get_time() - ft_get_last_meal(&info->philosophers[index]) ;
	if (time_since > info->time_2_die)
		return (1);
	return (0);
}
