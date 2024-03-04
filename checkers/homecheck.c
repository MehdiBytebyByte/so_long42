/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   homecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:56:43 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 16:45:35 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_struct	bigcheckfunc(t_struct data)
{
	namecheck(data);
	data.fd = opencheck(data);
	data = mapreader(data);
	data = doublenewcheck(data);
	data = collectioncount(data);
	data = datafiller(data);
	data = shapecheck(data);
	if (!midlines(data) || !diffkeyscheck(data))
		iexit(data, 4);
	numcheck(data);
	if (!firstandlast(data.map2[data.lines]) || !firstandlast(data.map2[0]))
		iexit(data, 4);
	data = pathcheck(data);
	data = ffcheck(data);
	return (data);
}
