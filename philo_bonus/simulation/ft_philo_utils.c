/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:16:29 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/29 15:49:26 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

void	ft_philo_take_forks(t_philo *philo)
{
	sem_wait(philo->info->forks);
	ft_print_message(philo, "has taken a fork");
	sem_wait(philo->info->forks);
	ft_print_message(philo, "has taken a fork");
}

void	ft_philo_release_forks(t_philo *philo)
{
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
}
