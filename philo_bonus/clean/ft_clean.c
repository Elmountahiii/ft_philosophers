/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:37:04 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/26 21:02:51 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

void	ft_clean(t_general_info *info)
{
	sem_close(info->forks);
	sem_close(info->start_lock);
	sem_unlink(SEM_FORKS_NAME);
	sem_unlink(SEM_LOCK_NAME);
	free(info);
}
