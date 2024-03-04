/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:08:57 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 17:47:17 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end(t_struct *d)
{
	mlx_destroy_window(d->mlx, d->w);
	write(1, "Game exited\n", 13);
	exit(0);
}

t_struct	*move_right(t_struct *d)
{
	if (d->map2[d->px][d->py + 1] == '1')
		return (d);
	if (d->map2[d->px][d->py + 1] == 'E' && d->co_count)
		return (d);
	d->moves += 1;
	ft_printf("Moves -> %d\n", d->moves);
	d->py = d->py + 1;
	if (d->map2[d->px][d->py] == 'E' && !d->co_count)
	{
		write(1, "You Win\n", 9);
		end(d);
	}
	if (d->map2[d->px][d->py] == 'C')
	{
		d->map2[d->px][d->py] = '0';
		mlx_put_image_to_window(d->mlx, d->w, d->flr, d->py * 64, d->px * 64);
		d->co_count--;
		ft_printf("collectibles -> %d\n", d->co_count);
	}
	mlx_put_image_to_window(d->mlx, d->w, d->player, d->py * 64, d->px * 64);
	mlx_put_image_to_window(d->mlx, d->w, d->flr, (d->py - 1) * 64, d->px * 64);
	return (d);
}

t_struct	*move_left(t_struct *d)
{
	if (d->map2[d->px + 1][d->py] == '1')
		return (d);
	if (d->map2[d->px + 1][d->py] == 'E' && d->co_count)
		return (d);
	d->moves += 1;
	ft_printf("Moves -> %d\n", d->moves);
	d->px = d->px + 1;
	if (d->map2[d->px][d->py] == 'E' && !d->co_count)
	{
		write(1, "You Win\n", 9);
		end(d);
	}
	if (d->map2[d->px][d->py] == 'C')
	{
		d->map2[d->px][d->py] = '0';
		mlx_put_image_to_window(d->mlx, d->w, d->flr, d->py * 64, d->px * 64);
		d->co_count--;
		ft_printf("collectibles -> %d\n", d->co_count);
	}
	mlx_put_image_to_window(d->mlx, d->w, d->player, d->py * 64, d->px * 64);
	mlx_put_image_to_window(d->mlx, d->w, d->flr, d->py * 64, (d->px - 1) * 64);
	return (d);
}

t_struct	*move_down(t_struct *d)
{
	if (d->map2[d->px][d->py - 1] == '1')
		return (d);
	if (d->map2[d->px][d->py - 1] == 'E' && d->co_count)
		return (d);
	d->moves += 1;
	ft_printf("Moves -> %d\n", d->moves);
	d->py = d->py - 1;
	if (d->map2[d->px][d->py] == 'E' && !d->co_count)
	{
		write(1, "You Win\n", 9);
		end(d);
	}
	if (d->map2[d->px][d->py] == 'C')
	{
		d->map2[d->px][d->py] = '0';
		mlx_put_image_to_window(d->mlx, d->w, d->flr, d->py * 64, d->px * 64);
		d->co_count--;
		ft_printf("collectibles -> %d\n", d->co_count);
	}
	mlx_put_image_to_window(d->mlx, d->w, d->player, d->py * 64, d->px * 64);
	mlx_put_image_to_window(d->mlx, d->w, d->flr, (d->py + 1) * 64, d->px * 64);
	return (d);
}

t_struct	*move_up(t_struct *d)
{
	if (d->map2[d->px - 1][d->py] == '1')
		return (d);
	if (d->map2[d->px - 1][d->py] == 'E' && d->co_count)
		return (d);
	d->moves += 1;
	ft_printf("Moves -> %d\n", d->moves);
	d->px = d->px - 1;
	if (d->map2[d->px][d->py] == 'E' && !d->co_count)
	{
		write(1, "You Win\n", 9);
		end(d);
	}
	if (d->map2[d->px][d->py] == 'C')
	{
		d->map2[d->px][d->py] = '0';
		mlx_put_image_to_window(d->mlx, d->w, d->flr, d->py * 64, d->px * 64);
		d->co_count--;
		ft_printf("collectibles -> %d\n", d->co_count);
	}
	mlx_put_image_to_window(d->mlx, d->w, d->player, d->py * 64, d->px * 64);
	mlx_put_image_to_window(d->mlx, d->w, d->flr, d->py * 64, (d->px + 1) * 64);
	return (d);
}
