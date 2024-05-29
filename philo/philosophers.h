/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:58:03 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/29 22:47:36 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include<unistd.h>

typedef struct s_philo
{
	int	philo_num;
	int	eat_time;
	int	sleep_time;
	int die_time;
	int	eat_count;
} t_philo;

// utils
int	ft_atoi(char *str);
int	ft_isdigit(int d);
int	ft_validate_args(char ** argc);
int	ft_init_philo(t_philo *philo, int argc, char **argv);
void	ft_run_thread();

#endif