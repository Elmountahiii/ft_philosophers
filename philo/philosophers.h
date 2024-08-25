/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:58:03 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/25 12:18:59 by yel-moun         ###   ########.fr       */
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

typedef struct s_philo
{
	int				philo_num;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			die_time;
	size_t			eat_count;
	size_t			start_time;
	bool			died;
	size_t			all_eaten;
	pthread_mutex_t	*all_eaten_lock;
	pthread_mutex_t	*died_lock;
	pthread_mutex_t	*print_lock;
	pthread_t		*treads;
	pthread_mutex_t	*forks;
	struct s_data	*philo_data; //philos
}	t_philo;

typedef struct s_data
{
	int				id;
	pthread_t		thread_id;
	size_t			time2eat;
	size_t			time2die;
	size_t			time2sleep;
	size_t			last_meal;
	int				eat_count;
	t_philo			*all_philo;
	pthread_mutex_t	*eaten_lock;
	pthread_mutex_t	*last_meal_lock;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_data;

// utils
int		ft_atoi(char *str);
int		ft_isdigit(int d);
int		ft_validate_args(char **argc);
void	ft_print_error(char *error);
void	ft_print_success(char *message);
void	ft_play_with_time(t_philo *philo);
void	ft_run_thread(t_philo *philo);
size_t	ft_get_time(void);
int		ft_sleep(t_general_info *info,	size_t time2sleep);
// treads
int		ft_init_mutexes(t_general_info *info);
int		ft_init_info(t_general_info **info, int argc, char **argv);
int		ft_init_philosophers(t_general_info *info);
int		ft_init_numbers(t_general_info **info,  char **argv);
//simulation
void	ft_start_simulation(t_general_info *info);
void	*ft_simulation(void *data);
void	ft_monitoring(t_general_info *info);
void	ft_print_philo_info(t_philosopher *philo); // to delete
int		ft_log(t_philosopher *philo, char *str);
int		ft_think(t_philosopher *philo);
int		ft_take_forks(t_philosopher *philo);
int		ft_go_sleep(t_philosopher *philo);
int		ft_put_forks(t_philosopher *philo);
int		ft_eat(t_philosopher *philo);
int		ft_check_philo_exit(t_philosopher *philo);
void	ft_print_died(t_philosopher *philo);
// setters and getters
void	ft_set_last_meal(t_philosopher *philo, size_t time);
size_t	ft_get_last_meal(t_philosopher *philo);
bool	ft_get_exit(t_general_info *info);
void	ft_set_exit(t_general_info *info, bool exit);
bool	ft_get_dead(t_general_info *info);
void	ft_set_dead(t_general_info *info, bool dead);
int		ft_get_simulation_end(t_general_info *info);
void	ft_set_simulation_end(t_general_info *info);
#endif