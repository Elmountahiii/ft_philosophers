/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:23:18 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/27 11:13:30 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*ft_simulation(void *data)
{
	t_philosopher *philo;
	philo = (t_philosopher *) data;
	if (philo->id % 2 == 0)
			ft_go_sleep(philo);
	while (1)
	{
		ft_think(philo);
		ft_take_forks(philo);
		ft_eat(philo);
		ft_put_forks(philo);
		ft_go_sleep(philo);
		if(ft_check_philo_exit(philo))
			break;
	}
	pthread_mutex_lock(philo->general_info->simulation_end_lock);
	philo->general_info->simulation_end++;
	pthread_mutex_unlock(philo->general_info->simulation_end_lock);
	return (NULL);
}