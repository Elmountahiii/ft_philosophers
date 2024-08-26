/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:12:52 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/26 22:42:53 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

void	routine(t_philo *philo)
{
	int	i;

	i = 0;
	sem_wait(philo->info->start_lock);
	printf("id: %d starts\n",philo->id);
	while (i < 10)
	{
		printf("process %d says hey\n", philo->id);
		i ++;
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