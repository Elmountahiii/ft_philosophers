/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:12:52 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/29 16:44:23 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

void	*ft_self_monitor(void *data)
{
	t_philo	*philo;
	size_t	time_since;

	philo = (t_philo *) data;
	while (1)
	{
		time_since = ft_get_time() - philo->last_meal;
		if (time_since >= philo->info->time_2_die)
		{
			ft_print_died(philo);
			exit(1);
		}
		usleep(400);
	}
	return (NULL);
}

void	routine(t_philo *philo)
{
	philo->last_meal = ft_get_time();
	pthread_create(&philo->monitor, NULL, ft_self_monitor, philo);
	pthread_detach(philo->monitor);
	if (philo->id % 2 == 0)
	{
		ft_print_message(philo, "is sleeping");
		ft_sleep(philo->info->time_2_sleep);
	}
	while (1)
	{
		ft_print_message(philo, "is thinking");
		ft_philo_take_forks(philo);
		philo->last_meal = ft_get_time();
		ft_print_message(philo, "is eating");
		ft_sleep(philo->info->time_2_eat);
		philo->meal_count ++;
		ft_philo_release_forks(philo);
		ft_print_message(philo, "is sleeping");
		ft_sleep(philo->info->time_2_sleep);
		if (philo->info->meal_target != -1
			&& philo->meal_count == philo->info->meal_target)
			ft_philo_release(philo, 0);
	}
	ft_philo_release(philo, 1);
}

void	ft_wait_and_kill(t_general_info *info)
{
	int	i;
	int	status;

	i = 0;
	while (waitpid(-1, &status, 0) > 0)
	{
		if (status == 256)
		{
			while (i < info->philo_num)
			{
				kill(info->philo[i].pid, SIGKILL);
				i ++;
			}
			break ;
		}
	}
}

void	ft_lunch_process(t_general_info *info)
{
	int		i;

	i = 0;
	info->start_time = ft_get_time();
	while (i < info->philo_num)
	{
		info->philo[i].pid = fork();
		if (info->philo[i].pid == 0)
			routine(&info->philo[i]);
		if (info->philo[i].pid < 0)
			break ;
		i ++;
	}
	ft_wait_and_kill(info);
}
