/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 22:30:50 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/29 22:49:52 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../philosophers.h"

void	*thread_one_job()
{
	int i;

	i = 1;
	while (1)
	{
		printf("thread one says %d\n",i);
		i ++;
		sleep(1);
	}
	return NULL;
}

void	*thread_two_job()
{
	int i;

	i = 1;
	while (1)
	{
		printf("\033[0;34mthread two says %d\n\033[0m",i);
		i ++;
		sleep(3);
	}
	return NULL;
}

void	ft_run_thread()
{
	pthread_t t_1;
	pthread_t t_2;
	int res = pthread_create(&t_1, NULL, thread_one_job, NULL);
	if (res == -1)
	{
		printf("\033[0;31mError creating thread.\n\033[0m");
		return;
	}
	res = pthread_create(&t_2, NULL, thread_two_job, NULL);
	if (res == -1)
	{
		printf("\033[0;31mError creating thread.\n\033[0m");
		return;
	}
	pthread_join(t_1, NULL);
	pthread_join(t_2, NULL);

}