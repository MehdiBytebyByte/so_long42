/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:56:50 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 17:46:29 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_struct	shapecheck(t_struct d)
{
	int		j;
	size_t	len;

	j = 0;
	while (j <= d.lines)
	{
		len = ft_strlen(d.map2[j]);
		if (len != ft_strlen(d.map2[0]))
			iexit(d, 4);
		j++;
	}
	return (d);
}

void	numcheck(t_struct d)
{
	int	i;
	int	p;
	int	c;
	int	e;

	e = 0;
	p = 0;
	c = 0;
	i = 0;
	while (d.map[i])
	{
		if (d.map[i] == 'P')
			p++;
		else if (d.map[i] == 'C')
			c++;
		else if (d.map[i] == 'E')
			e++;
		i++;
	}
	if (e != 1 || c <= 0 || p != 1)
		iexit(d, 4);
}

int	firstandlast(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

int	midlines(t_struct d)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < d.lines)
	{
		if (d.map2[i][0] != '1' || d.map2[i][d.colums - 1] != '1' )
			return (0);
		i++;
	}
	return (1);
}

int	diffkeyscheck(t_struct d )
{
	int	i;

	i = 0;
	while (d.map[i])
	{
		if (d.map[i] != '1' && d.map[i] != '0' && d.map[i] != 'P'
			&& d.map[i] != 'C'
			&& d.map[i] != 'E' && d.map[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
