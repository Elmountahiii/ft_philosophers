/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_with_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:43:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 21:41:19 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_play_with_time(t_philo *philo)
{
	struct timeval	start;
	struct timeval	current;
	time_t			elapsed;

	(void) philo;
	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&current, NULL);
		elapsed = current.tv_sec - start.tv_sec;
		printf("%ld second past \n", elapsed);
		sleep(1);
	}
}
