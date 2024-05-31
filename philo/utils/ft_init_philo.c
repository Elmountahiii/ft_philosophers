/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:57:58 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/31 16:52:38 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_init_philo(t_philo **philo, int argc, char **argv)
{
	*philo = malloc(sizeof(t_philo));
	if (!(*philo))
		return (1);
	(*philo)->philo_num = ft_atoi(argv[1]);
	(*philo)->die_time = ft_atoi(argv[2]);
	(*philo)->eat_time = ft_atoi(argv[3]);
	(*philo)->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
	{
		(*philo)->eat_count = ft_atoi(argv[5]);
		if ((*philo)->eat_count <= 0)
			return (1);
	}
	else
		(*philo)->eat_count = -1;
	if ((*philo)->philo_num <= 0 || (*philo)->die_time <= 0
		|| (*philo)->eat_time <= 0 || (*philo)->sleep_time <= 0)
		return (1);
	return (0);
}
