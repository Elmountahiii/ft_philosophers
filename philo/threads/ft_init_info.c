/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:57:58 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 21:48:30 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_init_info(t_general_info **info, int argc, char **argv)
{
	*info = malloc(sizeof(t_general_info));
	if (!(*info))
		return (1);
	(*info)->philo_num = ft_atoi(argv[1]);
	(*info)->time_2_die = ft_atoi(argv[2]);
	(*info)->time_2_eat = ft_atoi(argv[3]);
	(*info)->time_2_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		(*info)->meal_target = ft_atoi(argv[5]);
		if ((*info)->meal_target <= 0)
			return (1);
	}
	else
		(*info)->meal_target = -1;
	(*info)->simulation_end = 0;
	(*info)->is_dead = false;
	if (ft_init_mutexes(*info))
		return (1);
	if (ft_init_philosophers(*info))
		return (1);
	(*info)->simulation_start = ft_get_time();
	return (0);
}
