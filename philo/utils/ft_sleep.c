/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:50:46 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/02 10:47:26 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_sleep(t_general_info *info ,size_t time2sleep)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time2sleep)
	{
		if (ft_get_dead(info))
			return (1);
    	usleep(100);
	}
	return (0);
}
