/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxwindow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:13:30 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/02 18:48:55 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

void click(int keycode, void *params)
{
	t_mlx mlx = params.mlx;
    t_struct data = params->data;
    if (keycode == 53)
    {
        mlx_destroy_window(mlx->mlx, mlx->mlx_win);
        exit(0);
    }
}

int window(t_struct data)
{
	t_mlx mlx;
	t_params params;
	int w;
	int	h;
	
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx ,data.colums * 64, (data.lines + 1) * 64, "SO-LONG");
	mlx.floor = mlx_xpm_file_to_image(mlx.mlx,Floor, &h, &w);
	mlx.wall = mlx_xpm_file_to_image(mlx.mlx,Wall, &h, &w);
	mlx.player = mlx_xpm_file_to_image(mlx.mlx,Player, &h,&w);
	if(!mlx.player)
		(perror("Error"), exit(1));
	mlx.col = mlx_xpm_file_to_image(mlx.mlx,Col, &h, &w);
	mlx.end = mlx_xpm_file_to_image(mlx.mlx,End, &h, &w);
	mapinit(data, mlx);
	collectinit(data, mlx);
	mlx_hook(mlx.mlx_win, 2, 1L << 0, click, &a);
	mlx_loop(mlx.mlx);
	mlx_clear_window(mlx.mlx, mlx.mlx_win);
	return (1);
}
//	mlx_string_put(mlx.mlx, mlx.mlx_win, 10, 50, 0xFF0000, "SO---->LONG");