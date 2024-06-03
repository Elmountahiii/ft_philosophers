/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:50:46 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/03 21:05:03 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_sleep(size_t time2sleep)
{
	size_t start;
	size_t	current;

	start = ft_get_time();
	while (1)
	{
		usleep(100);
		current = ft_get_time();
		if (current - start >= time2sleep)
			break;
	}
}
