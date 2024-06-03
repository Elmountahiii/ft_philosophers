/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:04:52 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/03 20:48:28 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_init_philosophers(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_num)
	{
		philo->philo_data[i].thread_id = philo->treads[i];
		philo->philo_data[i].id = i + 1;
		philo->philo_data[i].last_meal = ft_get_time();
		philo->philo_data[i].time2die = philo->die_time;
		philo->philo_data[i].time2eat = philo->eat_time;
		philo->philo_data[i].time2sleep = philo->sleep_time;
		philo->philo_data[i].right_fork = &philo->forks[i];
		philo->philo_data[i].left_fork = &philo->forks[(i + 1) % philo->philo_num];
		philo->philo_data[i].all_philo = philo;
		philo->philo_data[i].last_meal_lock = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo->philo_data[i].last_meal_lock, NULL);
		i++;
	}
}

int	ft_init_forks(t_philo *philo)
{
	int	i;
	int status;

	i = 0;
	while (i < philo->philo_num)
	{
		status = pthread_mutex_init(&philo->forks[i], NULL);
		if (status == -1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_create_struct(t_philo *philo)
{
	philo->treads = malloc(sizeof(pthread_t) * philo->philo_num);
	if (!philo->treads)
	{
		ft_clean(philo);
		return (1);
	}
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->philo_num);
	if (!philo->forks || ft_init_forks(philo))
	{
		ft_clean(philo);
		return (1);
	}
	philo->philo_data = malloc(sizeof(t_data) * philo->philo_num);
	if (!philo->philo_data)
	{
		ft_clean(philo);
		return (1);
	}
	ft_init_philosophers(philo);
	return (0);
}
