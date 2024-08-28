/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:16:35 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/28 18:55:39 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <semaphore.h>
# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>
# include <signal.h>
# define	SEM_FORKS_NAME "/forks"
# define	SEM_LOCK_NAME  "/start_lock"
# define	SEM_PRINT_LOCK	"/print_lock"

typedef struct s_philo {
	int					pid;
	int					id;
	int					meal_count;
	size_t				last_meal;
	bool				is_dead;
	pthread_t			monitor;
	struct s_general_info *info;
}	t_philo;

typedef struct s_general_info
{
	int		philo_num;
	size_t	time_2_die;
	size_t	time_2_eat;
	size_t	time_2_sleep;
	size_t	start_time;
	int		meal_target;
	t_philo	*philo;
	size_t	simulation_start;
	sem_t	*print_lock;
	sem_t	*forks;
	sem_t	*start_lock;
} t_general_info;

// utils functions
int		ft_atoi(char *str);
int		ft_isdigit(int d);
void	ft_print_message(t_philo *philo,char *message);
size_t	ft_get_time(void);
int		ft_sleep(t_philo *philo, size_t time2sleep);
void	ft_print_died(t_philo *philo);
// init functions
int		ft_init_philos(t_general_info **info, int argc, char **argv);
// simulation functions
void	ft_simulation(t_general_info *info);
void	ft_lunch_process(t_general_info *info);
// clean functions
void	ft_clean(t_general_info *info);
#endif