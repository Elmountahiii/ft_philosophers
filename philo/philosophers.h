/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:58:03 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/01 00:26:56 by yel-moun         ###   ########.fr       */
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

typedef struct s_data
{
	int				id;
	pthread_t		thread_id;
	int				time2eat;
	int				time2die;
	int				time2sleep;
	int				last_meal;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
}	t_data;

typedef struct s_philo
{
	int				philo_num;
	int				eat_time;
	int				sleep_time;
	int				die_time;
	int				eat_count;
	pthread_t		*treads;
	pthread_mutex_t *forks;
	t_data			*philo_data;
} t_philo;

// utils
int		ft_atoi(char *str);
int		ft_isdigit(int d);
int		ft_validate_args(char **argc);
void	ft_print_error(char *error);
void	ft_print_success(char *message);
void	ft_play_with_time(t_philo *philo);
// treads
int		ft_init_struct(t_philo **philo, int argc, char **argv);
int		ft_create_struct(t_philo *philo);
void	ft_clean(t_philo *philo);
void	raise_condition();

#endif