/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:56:26 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 22:14:39 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	leaks_check(void)
{
	system("leaks philo");
}

int	main(int argc, char *argv[])
{
	t_general_info	*info;

	info = NULL;
	if (argc >= 5 && argc <= 6)
	{
		if (ft_validate_args(argv) || ft_init_info(&info, argc, argv))
		{
			ft_print_error("invalid arguments");
			return (1);
		}
		ft_start_simulation(info);
	}
	else
	{
		ft_print_error("invalid arguments count");
		return (1);
	}
	return (0);
}
