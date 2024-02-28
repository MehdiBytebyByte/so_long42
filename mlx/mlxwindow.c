/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxwindow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:13:30 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/28 19:44:50 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"



typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	doclose(int keycode, t_vars *vars)
{
	keycode++;
	keycode--;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}



// void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int window(t_struct data)
{
	
	
	
	
	
	
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		iexit(data, 6);
	
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, doclose, &vars);
	mlx_loop(vars.mlx);
	
	
	
	// void	*mlx;
	// void	*mlx_win;
	// // t_mlx	img;
	
	// mlx = mlx_init();
	// if(mlx == NULL)
	// 	iexit(data, 6);
	// mlx_win = mlx_new_window(mlx,data.colums * 100, data.lines * 100, "SO_LONG");
	// mlx_loop(mlx);
	return(1);
}
