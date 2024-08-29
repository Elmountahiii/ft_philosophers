/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_died.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:05:11 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/29 14:08:59 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

void	ft_print_died(t_philo *philo)
{
	sem_wait(philo->info->print_lock);
	printf("\033[0;31m%ld %d died \n\033[0m",
		ft_get_time() - philo->info->start_time, philo->id);
}
