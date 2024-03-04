/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:32:24 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 14:52:12 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	click(int keycode, void *param)
{
	t_struct	*data;

	data = (t_struct *)param;
	if (keycode == 53)
		end(data);
	if (keycode == 2)
		data = move_right(data);
	if (keycode == 1)
		data = move_left(data);
	if (keycode == 0)
		data = move_down(data);
	if (keycode == 13)
		data = move_up(data);
	return (0);
}
