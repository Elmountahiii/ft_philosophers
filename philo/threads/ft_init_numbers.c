/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:13:31 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/25 12:20:10 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_init_numbers(t_general_info **info,  char **argv)
{
	int	time_2_eat;
	int	time_2_sleep;
	int	time_2_die;
	int	philo_num;

	philo_num = ft_atoi(argv[1]);
	time_2_die = ft_atoi(argv[2]);
	time_2_eat = ft_atoi(argv[3]);
	time_2_sleep = ft_atoi(argv[4]);
	if (philo_num <= 0 || time_2_die <= 0 || time_2_eat <= 0 || time_2_sleep <= 0)
		return (1);
	(*info)->philo_num = philo_num;
	(*info)->time_2_die = time_2_die;
	(*info)->time_2_eat = time_2_eat;
	(*info)->time_2_sleep = time_2_sleep;
	return (0);
}
