/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:35:27 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/01 14:54:40 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_go_sleep(t_philosopher *philo)
{
	ft_log(philo, "is sleeping");
	ft_sleep(philo->general_info->time_2_sleep);
}
