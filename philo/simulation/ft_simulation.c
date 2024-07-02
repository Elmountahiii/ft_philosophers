/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:23:18 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/02 10:27:32 by yel-moun         ###   ########.fr       */
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
		if(ft_get_dead(philo->general_info))
			break;
		ft_think(philo);
		ft_take_forks(philo);
		ft_eat(philo);
		ft_put_forks(philo);
		ft_go_sleep(philo);
	}
	pthread_mutex_lock(philo->general_info->simulation_end_lock);
	philo->general_info->simulation_end++;
	pthread_mutex_unlock(philo->general_info->simulation_end_lock);
	return (NULL);
}