/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:12:52 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/28 19:02:46 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

void	*ft_self_monitor(void *data)
{
	t_philo *philo;
	size_t	time_since;
	philo = (t_philo *) data;
	while (1)
	{
		time_since = ft_get_time() - philo->last_meal;
		if (time_since > philo->info->time_2_die)
		{
			philo->is_dead = true;
			ft_print_died(philo);
			exit(10);
			break;
		}
		usleep(400);
	}
	return (NULL);
}

void	routine(t_philo *philo)
{
	sem_wait(philo->info->start_lock);
	philo->last_meal = ft_get_time();
	pthread_create(&philo->monitor,NULL, ft_self_monitor,philo);
	pthread_detach(philo->monitor);
	if (philo->id % 2 == 0)
	{
		ft_print_message(philo, "is sleeping");
		ft_sleep(philo,philo->info->time_2_sleep);
	}
	while (1)
	{
		ft_print_message(philo,"is thinking");
		sem_wait(philo->info->forks);
		ft_print_message(philo, "has taken a fork");
		sem_wait(philo->info->forks);
		ft_print_message(philo, "has taken a fork");
		philo->last_meal = ft_get_time();
		ft_print_message(philo, "is eating");
		if (ft_sleep(philo,philo->info->time_2_eat))
			break;
		philo->meal_count ++;
		sem_post(philo->info->forks);
		sem_post(philo->info->forks);
		ft_print_message(philo, "is sleeping");
		if (ft_sleep(philo,philo->info->time_2_sleep))
			break;
		if (philo->info->meal_target != -1 && philo->meal_count == philo->info->meal_target)
		{
			sem_post(philo->info->forks);
			sem_post(philo->info->forks);	
			exit(12);
			break;
		}
	}
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
	exit(10);
}


void	ft_lunch_process(t_general_info *info)
{
	int		i;
	int		status;
	
	i = 0;
	info->start_time = ft_get_time();
	while (i < info->philo_num)
	{
		info->philo[i].pid = fork();
		if (info->philo[i].pid == 0)
		{
			routine(&info->philo[i]);
		}
		i ++;
	}
	i = 0;
	while (i < info->philo_num)
	{
		sem_post(info->start_lock);
		i ++;
	}
	i = 0;
	while (waitpid(-1, &status, 0) > 0)
	{
		if (status == 10)
		{
			while (i < info->philo_num)
		{
			kill(info->philo[i].pid,SIGKILL);
			i ++;
		}
		break;	
		}
	}
	
}