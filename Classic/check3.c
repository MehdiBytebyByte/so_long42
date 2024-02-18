/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:11:42 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/18 23:34:46 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_struct doublenewcheck(t_struct data)
{
	int i;

	i = 0;
	while (data.map[i])
	{
		if (data.map[i] == '\n' && data.map[i + 1] == '\n')
		{
			iexit(data, 3);
		}
		i++;		
	}
	data.map2 = ft_split(data.map, '\n');
	return(data);
}