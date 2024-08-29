/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_release.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:11:37 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/29 16:09:27 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

void	ft_philo_release(t_philo *philo, int exit_code)
{
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
	exit(exit_code);
}
