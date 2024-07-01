/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_monitor_exit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:55:45 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/01 13:17:24 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_check_monitor_exit(t_general_info *info)
{
	if (ft_read_check(info))
		return (0);
	if (ft_get_semend(info) == info->philo_num)
	{
		ft_edit_exit(info,true);
		return (0);
	}
	return (1);
}
