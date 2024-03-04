/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:47:02 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 16:45:56 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_struct	datafiller(t_struct data)
{
	int	i;

	i = 0;
	data.colums = 0;
	data.lines = 0;
	data.len = ft_strlen(data.map);
	while (data.map[data.colums] && data.map[data.colums] != '\n')
		data.colums++;
	while (data.map[i])
	{
		if (data.map[i] == '\n')
			data.lines++;
		i++;
	}
	return (data);
}

t_struct	collectioncount(t_struct data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (data.map[i] != '\0')
	{
		if (data.map[i] == 'C')
			count++;
		i++;
	}
	data.co_count = count;
	return (data);
}
