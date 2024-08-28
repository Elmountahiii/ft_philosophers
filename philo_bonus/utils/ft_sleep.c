/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:09:15 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/28 14:05:54 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

int	ft_sleep(t_philo *philo, size_t time2sleep)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time2sleep)
	{
		if (philo->is_dead)
			return (1);
		usleep(400);
	}
	return (0);
}