/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:16:35 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/26 21:41:48 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <semaphore.h>

# define	SEM_FORKS_NAME "/forks"
# define	SEM_LOCK_NAME  "/start_lock"

typedef struct s_philo {
	int	id;
	int	meal_count;
	struct s_general_info *info;
}	t_philo;

typedef struct s_general_info
{
	int		philo_num;
	int		time_2_die;
	int		time_2_eat;
	int		time_2_sleep;
	int		meal_target;
	t_philo	*philo;
	size_t	simulation_start;
	sem_t	*forks;
	sem_t	*start_lock;
} t_general_info;

// utils functions
int		ft_atoi(char *str);
int		ft_isdigit(int d);
// init functions
int		ft_init_philos(t_general_info **info, int argc, char **argv);
// simulation functions
void	ft_simulation(t_general_info *info);
void	ft_lunch_process(t_general_info *info);
// clean functions
void	ft_clean(t_general_info *info);
#endif