/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:58:03 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/27 14:17:06 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_general_info
{
	int						philo_num;
	int						simulation_end;
	int						meal_target;
	size_t					simulation_start;
	size_t					time_2_die;
	size_t					time_2_sleep;
	size_t					time_2_eat;
	bool					is_dead;
	bool					exit;
	pthread_mutex_t			*exit_lock;
	pthread_mutex_t			*is_dead_lock;
	pthread_mutex_t			*print_lock;
	pthread_mutex_t			*simulation_end_lock;
	pthread_mutex_t			*forks;
	struct s_philosopher	*philosophers;
}	t_general_info;

typedef struct s_philosopher
{
	int					id;
	int					meal_count;
	size_t				last_meal_time;
	pthread_t			thread;
	pthread_mutex_t		*last_meal_lock;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*meal_count_lock;
	t_general_info		*general_info;
}	t_philosopher;

// utils
int		ft_atoi(char *str);
int		ft_isdigit(int d);
int		ft_validate_args(char **argc);
void	ft_print_error(char *error);
size_t	ft_get_time(void);
void	ft_sleep(size_t time2sleep);
// treads
int		ft_init_mutexes(t_general_info *info);
int		ft_init_info(t_general_info **info, int argc, char **argv);
int		ft_init_philosophers(t_general_info *info);
//simulation
void	ft_start_simulation(t_general_info *info);
void	*ft_simulation(void *data);
void	ft_monitoring(t_general_info *info);
void	ft_print_philo_info(t_philosopher *philo); // to delete
void	ft_log(t_philosopher *philo, char *str);
void	ft_think(t_philosopher *philo);
void	ft_take_forks(t_philosopher *philo);
void	ft_go_sleep(t_philosopher *philo);
void	ft_put_forks(t_philosopher *philo);
void	ft_eat(t_philosopher *philo);
int		ft_check_philo_exit(t_philosopher *philo);
void	ft_print_died(t_philosopher *philo);
int		ft_check_death(t_general_info *info, int index);
void	ft_check_monitor_exit(t_general_info *info);
//clean
void	ft_clean(t_general_info *info);
void	ft_clean_mutexes(t_general_info *info);
void	ft_free(t_general_info *info);

#endif