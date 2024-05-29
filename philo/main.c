/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:56:26 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/29 22:48:43 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char *argv[])
{
	t_philo *philo;

	philo = NULL;
	if (argc >= 5 && argc <= 6)
	{
		if (ft_validate_args(argv) || ft_init_philo(philo, argc, argv))
		{
			printf("\033[0;31minvalid arguments.\n\033[0m");
			return (1);
		}
		printf("\033[0;32mvalid.\n\033[0m");
		ft_run_thread();
	}
	else
	{
		printf("\033[0;31minvalid arguments count.\n\033[0m");
		return (1);
	}
	return 0;
}
