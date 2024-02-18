/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxwindow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:13:30 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/16 19:07:56 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;



void window(void)
{
	void	*mlx;
	void	*mlx_win;
	// t_data	img;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 720, 480, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	
	
	
	


	mlx_loop(mlx);

}
