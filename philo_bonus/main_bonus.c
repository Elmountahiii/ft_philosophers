/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:15:10 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/26 19:40:36 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int main(int argc, char *argv[])
{
	t_general_info	*info;

	info = malloc(sizeof(t_general_info));
	if (!info)
	{
		printf("Error: malloc failed\n");
		return (1);
	}
	if (argc != 5 && argc != 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	memset(info, 0, sizeof(t_general_info));
	if (ft_init_philos(&info, argc, argv))
	{
		ft_clean(info);
		return (1);
	}
	ft_simulation(info);
	ft_clean(info);
	return 0;
}
