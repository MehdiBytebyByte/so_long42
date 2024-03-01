/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxwindow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:13:30 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/01 20:41:15 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"



typedef struct	s_mlx 
{
	void	*mlx;
	void	*mlx_win;
	void	*player;
	void	*floor;
	void	*wall;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_mlx;


int calculate_window_size(int map_width, int map_height, int tile_width, int tile_height)
{
    return (map_width * tile_width) + (map_height * tile_height);
}

int window(t_struct data)
{
	t_mlx mlx;

	int w,h;
	int i;
	int j;
	
	
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx ,data.colums * 64, (data.lines + 1) * 64, "SO-LONG");
	//--------//
	mlx.floor = mlx_xpm_file_to_image(mlx.mlx,Floor, &h, &w);
	mlx.wall = mlx_xpm_file_to_image(mlx.mlx,Wall, &h, &w);
	mlx.player = mlx_xpm_file_to_image(mlx.mlx,Player, &h,&w);

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

	mlx_loop(mlx.mlx);
	mlx_clear_window(mlx.mlx, mlx.mlx_win);
	data.px = 1;
	return (1);
}
	// mlx_string_put(mlx.mlx, mlx.mlx_win, 10, 50, 0xFF0000, "SO---->LONG");