/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:32:24 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/06 20:11:51 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	closew(void *param)
{
	t_struct	*d;

	d = (t_struct *)param;
	mlx_destroy_window(d->mlx, d->w);
	write(1, "Window Closed\n", 15);
	cleaner(*d);
	close(d->fd);
	exit(0);
	return (0);
}

int	click(int keycode, void *param)
{
	t_struct	*d;

	d = (t_struct *)param;
	if (keycode == 53)
		end(d);
	if (keycode == 2)
		d = move_right(d);
	if (keycode == 1)
		d = move_left(d);
	if (keycode == 0)
		d = move_down(d);
	if (keycode == 13)
		d = move_up(d);
	return (1);
}
