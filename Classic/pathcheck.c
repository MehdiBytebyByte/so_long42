/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:14:08 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/25 20:36:18 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_struct findposition(t_struct data)
{
    int i;
    int j;

    i = 0;
    while (i < data.lines)
    {
        j = 0;
        while (j < data.colums)
        {
            if (data.map2[i][j] == 'P')
            {
                data.px = i;
                data.py = j;
                return (data);
            }
            j++;
        }
        i++;
    }
    return (data);
}

t_struct newmapallocater(t_struct data)
{
	int i;
	int j;

	j = 0;
	i = 0;
	data.newmap = (char **) malloc(sizeof(char *) * (data.lines  + 1));
	if(!data.newmap)
		iexit(data, 4);
	while (i < data.lines + 1)
	{
		data.newmap[i] = (char *)malloc(sizeof(char) * (data.colums  + 1));
		if (!data.newmap)
			{
				while (j < i)
					free(data.newmap[j++]);
				free(data.newmap[j]);
				iexit(data, 4);
			}
		i++;
	}
	return (data);
}
t_struct newmapcoppier(t_struct data)
{
	int i;
	int j;

	i = 0;
	while (i < data.lines + 1)
	{
		j = 0;
		while (j < data.colums + 1)
		{
			data.newmap[i][j] = data.map2[i][j];
			j++;
		}
		i++;
	}
	return (data);	
}
t_struct floodFill(t_struct data, int x, int y)
{

   if (x < 0 || x >= data.lines || y < 0 || y >= data.colums 
   || (data.newmap[x][y] != '0' && data.newmap[x][y] != 'P' && data.newmap[x][y] != 'C'
   && data.newmap[x][y] != 'E'))
        return (data);
    data.newmap[x][y] = 'R';
    data = floodFill(data, x + 1, y);
    data = floodFill(data, x - 1, y);
    data = floodFill(data, x, y + 1);
    data = floodFill(data, x, y - 1);
    return (data);
}


t_struct pathcheck(t_struct data)
{
	int i;
	
	data = findposition(data);
	data = newmapallocater(data);
	data = newmapcoppier(data);
	data = floodFill(data, data.px, data.py);
	i = 0;
	while (i < data.lines + 1)
	{
		printf("%s\n",data.newmap[i]);
		i++;
	}
	return (data);
}