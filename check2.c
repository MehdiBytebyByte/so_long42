/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:56:50 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/17 17:01:26 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_struct shapecheck(t_struct data)
{
	int i;
	
	i = 0;
	data.firstnl = 0;
	data.lines = 0;
	data.len = ft_strlen(data.map);
	while (data.map[data.firstnl] && data.map[data.firstnl] != '\n')
		data.firstnl++;
	while (data.map[i])
	{
		if (data.map[i] == '\n')
			data.lines++;
		i++;
	}
	data.lines++;
	data.len++;
	data.firstnl++;
	if (data.len / data.lines == data.firstnl && data.lines > 2 && data.firstnl > 3)
		return (data);
	printf("SHApe");
	iexit(data, 3);
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
	if (e != 1 || c <= 0 || p != 1){
		printf("EPC");		
		iexit(data, 3);
	}
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
	while (i < data.lines - 1)
	{
		if (data.map2[i][0] != '1' || data.map2[i][data.firstnl - 2 ] != '1')
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