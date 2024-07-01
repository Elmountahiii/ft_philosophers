/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:35:27 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/01 10:05:11 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_go_sleep(t_philosopher *philo)
{
	if (ft_log(philo, "is sleeping"))
		return (1);
	if (ft_sleep(philo, philo->general_info->time_2_sleep))
		return (1);
	return (0);
}
