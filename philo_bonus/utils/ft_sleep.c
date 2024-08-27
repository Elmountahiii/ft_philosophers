/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:09:15 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/27 13:13:34 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

void	ft_sleep(size_t time2sleep)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time2sleep)
	{
		usleep(400);
	}
}