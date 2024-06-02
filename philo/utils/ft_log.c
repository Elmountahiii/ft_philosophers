/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:30:58 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/02 20:33:06 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_log(t_data *data, char *str)
{
	pthread_mutex_lock(&data->all_philo->print_lock);
	printf("%ld %d %s\n", ft_get_time()  - data->all_philo->start_time, data->id, str);
	pthread_mutex_unlock(&data->all_philo->print_lock);
}
