/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxwindow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:13:30 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 16:15:37 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_struct	allmlxinit(t_struct data)
{
	int	w;
	int	h;

	data.mlx = mlx_init();
	if (!data.mlx)
		(perror("Error"), exit(1));
	data.mlx_win = mlx_new_window(data.mlx, data.colums * 64, (data.lines + 1) * 64, "SO_LONG");
	if (!data.mlx_win)
		(perror("Error"), exit(1));
	data.floor = mlx_xpm_file_to_image(data.mlx, FLOOR, &h, &w);
	if (!data.floor)
		(perror("Error"), exit(1));
	data.wall = mlx_xpm_file_to_image(data.mlx, WALL, &h, &w);
	if (!data.wall)
		(perror("Error"), exit(1));
	data.player = mlx_xpm_file_to_image(data.mlx, PLAYER, &h, &w);
	if (!data.player)
		(perror("Error"), exit(1));
	data.col = mlx_xpm_file_to_image(data.mlx, COL, &h, &w);
	data.end = mlx_xpm_file_to_image(data.mlx, END, &h, &w);
	data.moves = 0;
	return (data);
}

int	window(t_struct data)
{
	data = allmlxinit(data);
	mapinit(data);
	collectinit(data);
	mlx_hook(data.mlx_win, 2, 1L << 0, click, &data);
	mlx_loop(data.mlx);
	return (1);
}
