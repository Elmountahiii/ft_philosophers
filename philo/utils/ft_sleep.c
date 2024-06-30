/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:50:46 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/30 22:51:04 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_sleep(size_t time2sleep)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time2sleep)
    	usleep(100);
}
