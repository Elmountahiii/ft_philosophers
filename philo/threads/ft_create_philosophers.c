/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philosophers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:04:52 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/31 16:54:38 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_create_philosophers(t_philo *philo)
{
	philo->treads = malloc(sizeof(pthread_t) * philo->philo_num);
	if (!philo->treads)
	{
		ft_clean(philo);
		return (1);
	}
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->philo_num);
	if (!philo->forks)
	{
		ft_clean(philo);
		return (1);
	}
	return (0);
}