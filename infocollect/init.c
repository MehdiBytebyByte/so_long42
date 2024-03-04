/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:47:02 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 17:46:29 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_struct	dfiller(t_struct d)
{
	int	i;

	i = 0;
	d.colums = 0;
	d.lines = 0;
	d.len = ft_strlen(d.map);
	while (d.map[d.colums] && d.map[d.colums] != '\n')
		d.colums++;
	while (d.map[i])
	{
		if (d.map[i] == '\n')
			d.lines++;
		i++;
	}
	return (d);
}

t_struct	collectioncount(t_struct d)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (d.map[i] != '\0')
	{
		if (d.map[i] == 'C')
			count++;
		i++;
	}
	d.co_count = count;
	return (d);
}
