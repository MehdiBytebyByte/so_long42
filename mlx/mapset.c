/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:21:24 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/02 16:22:06 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mapinit(t_struct data, t_mlx mlx)
{
	int i;
	int j;
	
	i = 0;
	while (i <= data.lines)
	{
		j = 0;
		while (j < data.colums)
		{
			if (data.map2[i][j] == '1')
				mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.wall, j * 64, i * 64);
			else
				mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.floor, j * 64, i * 64);
			j++;
		}
		i++;	
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.player, data.py * 64, data.px * 64);
}
void	collectinit(t_struct data, t_mlx mlx)
{
	int i;
	int j;
	
	i = 0;
	while (i <= data.lines)
	{
		j = 0;
		while (j < data.colums)
		{
			if (data.map2[i][j] == 'C')
				mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.col, j * 64, i * 64);
			if (data.map2[i][j] == 'E')
				mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.end, j * 64, i * 64);
			j++;
		}
		i++;	
	}
}