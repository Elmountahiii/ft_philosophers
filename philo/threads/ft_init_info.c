/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:57:58 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/26 01:24:38 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_init_info(t_general_info **info, int argc, char **argv)
{
	*info = malloc(sizeof(t_general_info));
	if (!(*info))
		return (1);
	memset(*info, 0, sizeof(t_general_info));
	if (ft_init_numbers(info, argv))
		return (1);
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
