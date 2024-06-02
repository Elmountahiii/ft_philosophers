/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_tread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:47:01 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/02 22:00:40 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"


void	ft_think(t_data *philo)
{
	ft_log(philo, "is thinking");
}

void	ft_take_forks(t_data *philo)
{
	pthread_mutex_lock(philo->right_fork);
	ft_log(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	ft_log(philo, "has taken a fork");
}

void	ft_put_forks(t_data *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	ft_eat(t_data *philo)
{
	philo->last_meal = ft_get_time();
	ft_log(philo, "is eating");
	ft_sleep(philo->time2eat);
}

void ft_go_sleep(t_data *philo)
{
	ft_log(philo, "is sleeping");
	ft_sleep(philo->all_philo->sleep_time);
}

void	*run(void *data)
{
	t_data *philo_data;

	philo_data = (t_data *) data;
	if (philo_data->id % 2 == 0)
		ft_go_sleep(philo_data);
	while (1)
	{
		ft_think(philo_data);
		ft_take_forks(philo_data);
		ft_eat(philo_data);
	 	ft_put_forks(philo_data);
		ft_go_sleep(philo_data);
	}
	
	return (NULL);
}

void	ft_run_thread(t_philo *philo)
{
	int i;

	i = 0;
	philo->start_time = ft_get_time();
	pthread_mutex_init(&philo->print_lock, NULL);
	while (i < philo->philo_num)
	{
		if (i % 2 == 0)
			usleep(100);
		pthread_create(&philo->philo_data[i].thread_id, NULL, run , &philo->philo_data[i]);
		i ++;
	}
	i = 0;
	while (i < philo->philo_num)
	{
		pthread_join(philo->philo_data[i].thread_id, NULL);
		i ++;
	}
}