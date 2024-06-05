/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:58:03 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/05 15:53:41 by yel-moun         ###   ########.fr       */
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


typedef struct s_philo
{
	int				philo_num;
	size_t				eat_time;
	size_t				sleep_time;
	size_t			die_time;
	size_t				eat_count;
	size_t			start_time;
	bool			died;
	pthread_mutex_t  *died_lock;
	pthread_mutex_t	print_lock;
	pthread_t		*treads;
	pthread_mutex_t *forks;
	struct s_data	*philo_data;
} t_philo;

typedef struct s_data
{
	int				id;
	pthread_t		thread_id;
	size_t				time2eat;
	size_t				time2die;
	size_t				time2sleep;
	size_t			last_meal;
	pthread_mutex_t *last_meal_lock;
	t_philo			*all_philo;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
}	t_data;


// utils
int		ft_atoi(char *str);
int		ft_isdigit(int d);
int		ft_validate_args(char **argc);
void	ft_print_error(char *error);
void	ft_print_success(char *message);
void	ft_play_with_time(t_philo *philo);
void	ft_run_thread(t_philo *philo);
size_t	ft_get_time();
void	ft_log(t_data *data, char *str);
void	ft_sleep(size_t time2sleep);
void	ft_print_died(t_data *philo);
// treads
int		ft_init_struct(t_philo **philo, int argc, char **argv);
int		ft_create_struct(t_philo *philo);
void	ft_clean(t_philo *philo);
void	raise_condition();

#endif