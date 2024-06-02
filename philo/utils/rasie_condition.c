/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasie_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 00:12:42 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/01 12:45:17 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

# define NUM_THREADS 2
int g_var = 100;
pthread_mutex_t mutex;

void * increment_global_var(void *arg)
{
	(void)arg; // to avoid warning (unused parameter
	int i = 0;
	pthread_mutex_lock(&mutex);
	printf("1 i found the global var: %d\n", g_var);
	while (i < 1000000)
	{
		g_var++;
		i++;
	}
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

void * decrement_global_var(void *arg)
{
	(void)arg; // to avoid warning (unused parameter
	int i = 0;
	pthread_mutex_lock(&mutex);
	printf("2 i found the global var: %d\n", g_var);
	while (i < 1000000)
	{
		g_var--;
		i++;
	}
	pthread_mutex_unlock(&mutex);
	return (NULL);
}
void	raise_condition()
{
	pthread_t threads[NUM_THREADS];

	int i = 0;

	pthread_mutex_init(&mutex, NULL);
			pthread_create(&threads[i], NULL, increment_global_var, NULL);
			pthread_create(&threads[i + 1], NULL, decrement_global_var, NULL);
	// while (i < NUM_THREADS)
	// {
	// 	i++;
	// }
	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	printf("Value of global var: %d\n", g_var);
}