/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:58:34 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/25 18:09:07 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_struct floodFill(t_struct data, int x, int y)
{\

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
t_struct ft_secondmap(t_struct data)
{
    int i;
    int j;
    
    data.newmap = (char **)malloc((data.lines +  1) * sizeof(char *));
    if (data.newmap == NULL)
        iexit(data, 3);
    for (i = 0; i < data.lines + 1; i++) {
        data.newmap[i] = (char *)malloc(data.colums);
        if(!data.newmap[i]) {
            for (j = 0; j < i; j++) {
                free(data.newmap[j]);
            }
            free(data.newmap);
            iexit(data,3);
        }
        for (j = 0; j < data.colums; j++) {
            data.newmap[i][j] = data.map2[i][j];
        }
    }
    data = findposition(data);
    data = floodFill(data, data.px, data.py);
    return (data);
}

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


    // Free memory for newmap
    // for (i = 0; i < data.lines; i++) {
    //     free(data.newmap[i]);
    // }
    // free(data.newmap);