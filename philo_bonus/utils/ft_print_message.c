/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:28:36 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/27 13:17:12 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

void	ft_print_message(t_philo *philo,char *message)
{
	sem_wait(philo->info->print_lock);
	printf("%ld %d %s\n",
		ft_get_time() - philo->info->start_time, philo->id, message);
	sem_post(philo->info->print_lock);
}
