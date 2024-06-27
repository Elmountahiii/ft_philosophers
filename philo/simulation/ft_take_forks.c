/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:42:48 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/25 12:43:58 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_take_forks(t_philosopher *philo)
{
	pthread_mutex_lock(philo->right_fork);
	ft_log(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	ft_log(philo, "has taken a fork");
}
