/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:16:35 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/26 01:42:06 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_general_info
{
	int		philo_num;
	int		time_2_die;
	int		time_2_eat;
	int		time_2_sleep;
	int		meal_target;
	size_t	simulation_start;
} t_general_info;

// utils functions
int	ft_atoi(char *str);
int	ft_isdigit(int d);
// init functions
int	ft_init_philos(t_general_info **info, int argc, char **argv);
// simulation functions
void	ft_simulation(t_general_info *info);
#endif