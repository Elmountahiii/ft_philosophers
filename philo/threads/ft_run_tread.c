/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_tread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:47:01 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/05 17:37:26 by yel-moun         ###   ########.fr       */
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
	ft_log(philo, "is eating");
	pthread_mutex_lock(philo->last_meal_lock);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(philo->last_meal_lock);
	ft_sleep(philo->time2eat);
}

void ft_go_sleep(t_data *philo)
{
	ft_log(philo, "is sleeping");
	ft_sleep(philo->time2sleep);
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

void detach_threads (t_philo *philo)
{
	int i = 0;
	while (i < philo->philo_num)
	{
		pthread_detach(philo->treads[i]);
		i ++;
	}
	
}

void	ft_run_thread(t_philo *philo)
{
	int i;

	i = 0;
	philo->start_time = ft_get_time();
	pthread_mutex_init(&philo->print_lock, NULL);
	while (i < philo->philo_num)
	{
		pthread_create(&philo->philo_data[i].thread_id, NULL, run , &philo->philo_data[i]);
		i ++;
	}
	while (1)
	{
		i = 0;
		while (i < philo->philo_num)
		{
			pthread_mutex_lock(philo->philo_data[i].last_meal_lock);
			size_t current = ft_get_time();
			size_t time_since = current - philo->philo_data[i].last_meal;
			pthread_mutex_unlock(philo->philo_data[i].last_meal_lock);
			if (time_since > philo->die_time)
			{
				pthread_mutex_lock(philo->died_lock);
				philo->died = true;
				pthread_mutex_unlock(philo->died_lock);
				ft_print_died(&philo->philo_data[i]);
				detach_threads(philo);
				break;
			}
			i ++;
		}	
		pthread_mutex_lock(philo->died_lock);
		if (philo->died)
		{
		return ;
		}
		pthread_mutex_unlock(philo->died_lock);
	}
	// i = 0;
	// while (i < philo->philo_num)
	// {
	// 	pthread_join(philo->philo_data[i].thread_id, NULL);
	// 	i ++;
	// }
}