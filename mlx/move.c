/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:08:57 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/03 21:20:28 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end(t_struct *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	write(1,"Game exited\n",13);
	exit(0);
}
t_struct	*move_right(t_struct *data)
{
	if(data->map2[data->px][data->py+1] == '1')
		return (data);
	if (data->map2[data->px][data->py+1] == 'E' && data->co_count)
		return (data);
	data->moves += 1;
	printf("Moves -> %d\n",data->moves);
	data->py = data->py + 1;
	if (data->map2[data->px][data->py] == 'E' && !data->co_count)
	{
		write(1,"You Win\n",9);
		end(data);
	}
	if (data->map2[data->px][data->py] == 'C')
	{
		data->map2[data->px][data->py] = '0';
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, data->py * 64, data->px * 64);
		data->co_count--;
		printf("collectibles -> %d\n",data->co_count);
	};
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, data->py* 64, data->px * 64);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, (data->py - 1)* 64, data->px * 64);
	return (data);
}

t_struct *move_left(t_struct *data)
{
	if(data->map2[data->px + 1][data->py] == '1')
		return (data);
	if (data->map2[data->px + 1][data->py] == 'E' && data->co_count)
		return (data);
	data->moves += 1;
	printf("Moves -> %d\n",data->moves);
	data->px = data->px + 1;
	if (data->map2[data->px][data->py] == 'E' && !data->co_count)
	{
		write(1,"You Win\n",9);
		end(data);
	}
	if (data->map2[data->px][data->py] == 'C')
	{
		data->map2[data->px][data->py] = '0';
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, data->py * 64, data->px * 64);
		data->co_count--;
		printf("collectibles -> %d\n",data->co_count);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, data->py* 64, data->px * 64);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, data->py * 64, (data->px - 1) * 64);
	return (data);
}
t_struct *move_down(t_struct *data)
{
	if(data->map2[data->px][data->py - 1] == '1')
		return (data);
	if (data->map2[data->px][data->py - 1] == 'E' && data->co_count)
		return (data);
	data->moves += 1;
	printf("Moves -> %d\n",data->moves);
	data->py = data->py - 1;
	if (data->map2[data->px][data->py] == 'E' && !data->co_count)
	{
		write(1,"You Win\n",9);
		end(data);
	}
	if (data->map2[data->px][data->py] == 'C')
	{
		data->map2[data->px][data->py] = '0';
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, data->py * 64, data->px * 64);
		data->co_count--;
		printf("collectibles -> %d\n",data->co_count);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, data->py* 64, data->px * 64);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, (data->py + 1)* 64, data->px * 64);;
	return (data);
}
t_struct *move_up(t_struct *data)
{
	if(data->map2[data->px - 1][data->py] == '1')
		return (data);
	if (data->map2[data->px - 1][data->py] == 'E' && data->co_count)
		return (data);
	data->moves += 1;
	printf("Moves -> %d\n",data->moves);
	data->px = data->px - 1;
	if (data->map2[data->px][data->py] == 'E' && !data->co_count)
	{
		write(1,"You Win\n",9);
		end(data);
	}
	if (data->map2[data->px][data->py] == 'C')
	{
		data->map2[data->px][data->py] = '0';
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, data->py * 64, data->px * 64);
		data->co_count--;
		printf("collectibles -> %d\n",data->co_count);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, data->py* 64, data->px * 64);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, data->py * 64, (data->px + 1) * 64);
	return (data);
}
 