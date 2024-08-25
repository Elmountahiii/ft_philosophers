/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:42:48 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/25 15:20:10 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_take_forks(t_philosopher *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (ft_log(philo, "has taken a fork"))
		return (1);
	pthread_mutex_lock(philo->left_fork);
	if (ft_log(philo, "has taken a fork"))
		return (1);
	return (0);
}
