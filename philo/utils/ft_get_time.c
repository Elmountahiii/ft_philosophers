/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:07:18 by yel-moun          #+#    #+#             */
/*   Updated: 2024/06/01 17:29:56 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long	ft_get_time()
{
	struct timeval tv;

	gettimeofday(&tv,NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
