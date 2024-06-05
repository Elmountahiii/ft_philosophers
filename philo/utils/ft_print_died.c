/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_died.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:46:29 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/05 17:38:15 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_print_died(t_data *philo)
{
	pthread_mutex_lock(&philo->all_philo->print_lock);
	printf("\033[0;31m%ld %d  has died \n\033[0m", ft_get_time()  - philo->all_philo->start_time , philo->id);
	pthread_mutex_unlock(&philo->all_philo->print_lock);
}
