/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:56:50 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/25 00:12:46 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_struct shapecheck(t_struct data)
{
	int j;
	size_t	len;

	j = 0;
	while (j <= data.lines)
	{
		len = ft_strlen(data.map2[j]); // issue here
		if (len != ft_strlen(data.map2[0]))
			iexit(data, 3);
		j++;
	}
	// printf("shapecheck Done");
	return (data);
}
void	numcheck(t_struct data)
{
	int i;
	int p;
	int c;
	int e;
	
	e = 0;
	p = 0;
	c = 0;
	i = 0;
	while (data.map[i])
	{
		if(data.map[i] ==  'P')
			p++;
		else if(data.map[i] == 'C')
			c++;
		else if(data.map[i] == 'E')
			e++;
		i++;
	}
	if (e != 1 || c <= 0 || p != 1)
		iexit(data, 3);
	// printf("ECP DONE !");
}
int	firstandlast(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(str[i] == '1')
			i++;
		else
			return (0);
	}
	return (1);
};
int	midlines(t_struct data)
{
	int i;
	int j;
	
	i = 1;
	j = 0;
	while (i < data.lines)
	{
		if (data.map2[i][0] != '1' || data.map2[i][data.colums - 1 ] != '1')
			return (0);
		i++;
	}
	return (1);
}
int	diffkeyscheck(t_struct data )
{
	int i;

	i = 0;
	while (data.map[i])
	{
		if(data.map[i] != '1' && data.map[i] != '0' && data.map[i] != 'P' && data.map[i] != 'C' && data.map[i] != 'E' && data.map[i] != '\n')
			return (0);
		i++;
	}
	return (1);
	
}