/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:32:24 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 17:46:29 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	return (0);
}
