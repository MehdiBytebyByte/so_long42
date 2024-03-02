/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:47:02 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/02 14:30:00 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_struct isetonull(t_struct data)
{
	data.fd = 0;
	data.colums = 0;
	data.lines = 0;
	data.len = 0;
	data.map2 = 0;
	data.map = 0;
	data.name = 0;
	data.newmap = 0;
	return (data);
}

t_struct Datafiller(t_struct data)
{
	int i;

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