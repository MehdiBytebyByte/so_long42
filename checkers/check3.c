/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:11:42 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/28 15:02:59 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_struct doublenewcheck(t_struct data)
{
	int i;

	i = 0;
	while (data.map[i])
	{
		if (data.map[i] == '\n' && (data.map[i + 1] == '\n' || data.map[i + 1] == '\0'))
			iexit(data, 4);
		i++;		
	}
	data.map2 = ft_split(data.map, '\n');
	return(data);
}
t_struct FFcheck(t_struct data)
{
	int i;
	int j;

	i = 0;
	while (i < data.lines + 1)
	{
		j = 0;
		while (j < data.colums)
		{
			if(data.newmap[i][j] != '0' && data.newmap[i][j] != '1' && data.newmap[i][j] != 'D')
				iexit(data, 5);
			j++;
		}
		i++;
	}
	freemap(data);
	return (data);
}
void freemap(t_struct data)
{
	int i;

	i = 0;
	while (i < data.lines + 1)
	{
		free(data.newmap[i]);
		i++;	
	}
	free(data.newmap);
	free(data.map);
}