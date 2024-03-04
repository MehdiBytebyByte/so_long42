/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:11:42 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 17:46:29 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_struct	doublenewcheck(t_struct d)
{
	int	i;

	i = 0;
	while (d.map[i])
	{
		if (d.map[i] == '\n' && (d.map[i + 1] == '\n'
				|| d.map[i + 1] == '\0'))
			iexit(d, 4);
		i++;
	}
	d.map2 = ft_split(d.map, '\n');
	return (d);
}

t_struct	ffcheck(t_struct d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d.lines + 1)
	{
		j = 0;
		while (j < d.colums)
		{
			if (d.newmap[i][j] != '0' && d.newmap[i][j] != '1'
				&& d.newmap[i][j] != 'D')
				iexit(d, 5);
			j++;
		}
		i++;
	}
	freemap(d);
	return (d);
}

void	freemap(t_struct d)
{
	int	i;

	i = 0;
	while (i < d.lines + 1)
	{
		free(d.newmap[i]);
		i++;
	}
	free(d.newmap);
	free(d.map);
}
