/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:12:52 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/27 13:24:29 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

void	routine(t_philo *philo)
{
	sem_wait(philo->info->start_lock);
	if (philo->id % 2 == 0)
	{
		ft_print_message(philo, "is sleeping");
		ft_sleep(philo->info->time_2_sleep);
	}
	while (1)
	{
		ft_print_message(philo,"is thinking");
		sem_wait(philo->info->forks);
		ft_print_message(philo, "has taken a fork");
		sem_wait(philo->info->forks);
		ft_print_message(philo, "has taken a fork");
		ft_print_message(philo, "is eating");
		ft_sleep(philo->info->time_2_eat);
		sem_post(philo->info->forks);
		sem_post(philo->info->forks);
		ft_print_message(philo, "is sleeping");
		ft_sleep(philo->info->time_2_sleep);
	}
	exit(0);
}

void	ft_lunch_process(t_general_info *info)
{
	pid_t	p_id;
	int		i;
	
	i = 0;
	while (i < info->philo_num)
	{
		p_id = fork();
		if (p_id == 0)
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
	
	while (wait(NULL) > 0)
	{
	}
}