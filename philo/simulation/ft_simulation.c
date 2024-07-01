/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:23:18 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/01 10:06:12 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*ft_simulation(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *) data;
	if (philo->id % 2 == 0)
		ft_go_sleep(philo);
	while (1)
	{
		if (ft_check_philo_exit(philo))
			break ;
		if (ft_think(philo))
			break ;
		ft_take_forks(philo);
		if (ft_eat(philo))
			break;
		ft_put_forks(philo);
		if (ft_go_sleep(philo))
			break ;
	}
	return (NULL);
}
