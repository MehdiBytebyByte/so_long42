/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:21:24 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 17:47:17 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mapinit(t_struct d)
{
	int	i;
	int	j;

	i = 0;
	while (i <= d.lines)
	{
		j = 0;
		while (j < d.colums)
		{
			if (d.map2[i][j] == '1')
				mlx_put_image_to_window(d.mlx, d.w, d.wall, j * 64, i * 64);
			else
				mlx_put_image_to_window(d.mlx, d.w, d.flr, j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(d.mlx, d.w, d.player, d.py * 64, d.px * 64);
}

void	collectinit(t_struct d)
{
	int	i;
	int	j;

	i = 0;
	while (i <= d.lines)
	{
		j = 0;
		while (j < d.colums)
		{
			if (d.map2[i][j] == 'C')
				mlx_put_image_to_window(d.mlx, d.w, d.col, j * 64, i * 64);
			if (d.map2[i][j] == 'E')
				mlx_put_image_to_window(d.mlx, d.w, d.end, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
