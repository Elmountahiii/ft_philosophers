/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:58:03 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/02 21:58:59 by yel-moun         ###   ########.fr       */
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
	int				eat_time;
	int				sleep_time;
	int				die_time;
	int				eat_count;
	size_t				start_time;
	pthread_mutex_t	print_lock;
	pthread_t		*treads;
	pthread_mutex_t *forks;
	struct s_data	*philo_data;
} t_philo;

typedef struct s_data
{
	int				id;
	pthread_t		thread_id;
	int				time2eat;
	int				time2die;
	int				time2sleep;
	int				last_meal;
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
long	ft_get_time();
void	ft_log(t_data *data, char *str);
void	ft_sleep(size_t time2sleep);
// treads
int		ft_init_struct(t_philo **philo, int argc, char **argv);
int		ft_create_struct(t_philo *philo);
void	ft_clean(t_philo *philo);
void	raise_condition();

#endif