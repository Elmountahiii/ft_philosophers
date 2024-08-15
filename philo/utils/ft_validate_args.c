/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:48:30 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 21:44:33 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_validate_args(char **argc)
{
	int	i;
	int	j;

	i = 1;
	while (argc && argc[i])
	{
		j = 0;
		while (argc[i][j])
		{
			if (!ft_isdigit(argc[i][j]))
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}
