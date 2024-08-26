/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:28:49 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/26 22:40:17 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

int	ft_open_sem(t_general_info **info)
{
	sem_unlink(SEM_FORKS_NAME);
	sem_unlink(SEM_LOCK_NAME);
	(*info)->forks = sem_open(SEM_FORKS_NAME, O_CREAT, 0644, (*info)->philo_num);
	(*info)->start_lock = sem_open(SEM_LOCK_NAME, O_CREAT, 0644, 0);
	if ((*info)->forks == SEM_FAILED || (*info)->start_lock == SEM_FAILED)
	{
		printf("Error : SEM_FAILED\n");
		return (1);
	}
	return (0);
}

int	init_philo_data(t_general_info **info)
{
	int	i;

	i = 0;
	(*info)->philo = malloc(sizeof(t_philo) * (*info)->philo_num);
	if (!(*info)->philo)
	{
		printf("Erro : malloc failed\n");
		return (1);
	}
	memset((*info)->philo, 0, sizeof(t_philo));
	while (i < (*info)->philo_num)
	{
		(*info)->philo[i].id = i +1;
		(*info)->philo[i].info = *info;
		i ++; 
	}
	return (0);
}

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
	return (ft_open_sem(info));
}

int	ft_init_philos(t_general_info **info, int argc, char **argv)
{
	if (ft_init_numbers(info, argc, argv))
	{
		printf("Error: wrong arguments\n");
		return (1);
	}
	if (init_philo_data(info))
		return (1);
	return (0);
}