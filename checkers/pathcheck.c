/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:14:08 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 21:46:54 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_struct	findposition(t_struct d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d.lines)
	{
		j = 0;
		while (j < d.colums)
		{
			if (d.map2[i][j] == 'P')
			{
				d.px = i;
				d.py = j;
				return (d);
			}
			j++;
		}
		i++;
	}
	return (d);
}

t_struct	newmapallocater(t_struct d)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	d.newmap = (char **) malloc(sizeof(char *) * (d.lines + 1));
	if (!d.newmap)
	{
		free (d.newmap);
		iexit(d, 6);
	}
	while (i < d.lines + 1)
	{
		d.newmap[i] = (char *)malloc(sizeof(char) * (d.colums + 1));
		if (!d.newmap[i])
		{
			while (j < i)
				free(d.newmap[j++]);
			free(d.newmap);
			iexit(d, 6);
		}
		i++;
	}
	return (d);
}

t_struct	newmapcoppier(t_struct d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d.lines + 1)
	{
		j = 0;
		while (j < d.colums + 1)
		{
			d.newmap[i][j] = d.map2[i][j];
			j++;
		}
		i++;
	}
	return (d);
}

t_struct	floodfill(t_struct d, int x, int y)
{
	if (x < 0 || x >= d.lines || y < 0 || y >= d.colums
		|| (d.newmap[x][y] != '0' && d.newmap[x][y] != 'P'
		&& d.newmap[x][y] != 'C' && d.newmap[x][y] != 'E'))
		return (d);
	d.newmap[x][y] = 'D';
	d = floodfill(d, x + 1, y);
	d = floodfill(d, x - 1, y);
	d = floodfill(d, x, y + 1);
	d = floodfill(d, x, y - 1);
	return (d);
}

t_struct	pathcheck(t_struct d)
{
	d = findposition(d);
	d = newmapallocater(d);
	d = newmapcoppier(d);
	d = floodfill(d, d.px, d.py);
	return (d);
}
