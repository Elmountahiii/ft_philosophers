/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:23:18 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 22:46:49 by yel-moun         ###   ########.fr       */
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
		if (ft_get_dead(philo->general_info))
			break ;
		if (ft_think(philo))
			break ;
		if (ft_take_forks(philo))
			break ;
		if (ft_eat(philo))
			break ;
		if (ft_put_forks(philo))
			break ;
		if (ft_go_sleep(philo))
			break ;
	}
	return (NULL);
}
