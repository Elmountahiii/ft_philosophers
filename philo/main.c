/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:56:26 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/01 00:27:25 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char *argv[])
{
	t_philo *philo;

	philo = NULL;
	if (argc >= 5 && argc <= 6)
	{
		if (ft_validate_args(argv) || ft_init_struct(&philo, argc, argv))
		{
			ft_print_error("invalid arguments");
			return (1);
		}
		ft_print_success("valid arguments");
		ft_create_struct(philo);
		raise_condition();
	}
	else
	{
		ft_print_error("invalid arguments count");
		return (1);
	}
	return 0;
}
