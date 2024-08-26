/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:28:49 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/26 01:39:40 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

int	ft_init_numbers(t_general_info **info, int argc, char **argv)
{
	int	philos;
	int	t_2_die;
	int	t_2_eat;
	int	t_2_sleep;

	philos = ft_atoi(argv[1]);
	t_2_die = ft_atoi(argv[2]);
	t_2_eat = ft_atoi(argv[3]);
	t_2_sleep = ft_atoi(argv[4]);
	if (philos <= 0 || t_2_die <= 0 || t_2_eat <= 0 || t_2_sleep <= 0)
		return (1);
	if (argc == 6 && ft_atoi(argv[5]) > 0)
		(*info)->meal_target = ft_atoi(argv[5]);
	else
		(*info)->meal_target = -1;
	(*info)->philo_num = philos;
	(*info)->time_2_die = t_2_die;
	(*info)->time_2_eat = t_2_eat;
	(*info)->time_2_sleep = t_2_sleep;
}

int	ft_init_philos(t_general_info **info, int argc, char **argv)
{
	if (ft_init_numbers(info, argc, argv))
	{
		printf("Error: wrong arguments\n");
		return (1);
	}
	return (0);
}