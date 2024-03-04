/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxwindow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:13:30 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 17:51:05 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_struct	allmlxinit(t_struct d)
{
	int	w;
	int	h;

	d.mlx = mlx_init();
	if (!d.mlx)
		(perror("Error"), exit(1));
	d.w = mlx_new_window(d.mlx, d.colums * 64, (d.lines + 1) * 64, "SO_LONG");
	if (!d.w)
		(perror("Error"), exit(1));
	d.flr = mlx_xpm_file_to_image(d.mlx, FLR, &h, &w);
	if (!d.flr)
		(perror("Error"), exit(1));
	d.wall = mlx_xpm_file_to_image(d.mlx, WALL, &h, &w);
	if (!d.wall)
		(perror("Error"), exit(1));
	d.player = mlx_xpm_file_to_image(d.mlx, PLAYER, &h, &w);
	if (!d.player)
		(perror("Error"), exit(1));
	d.col = mlx_xpm_file_to_image(d.mlx, COL, &h, &w);
	d.end = mlx_xpm_file_to_image(d.mlx, END, &h, &w);
	d.moves = 0;
	return (d);
}

int	window(t_struct d)
{
	d = allmlxinit(d);
	mapinit(d);
	collectinit(d);
	mlx_hook(d.w, 2, 1L << 0, click, &d);
	mlx_loop(d.mlx);
	return (1);
}
