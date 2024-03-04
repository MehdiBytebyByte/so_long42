/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   homecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:56:43 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 17:46:29 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_struct	bigcheckfunc(t_struct d)
{
	namecheck(d);
	d.fd = opencheck(d);
	d = mapreader(d);
	d = doublenewcheck(d);
	d = collectioncount(d);
	d = dfiller(d);
	d = shapecheck(d);
	if (!midlines(d) || !diffkeyscheck(d))
		iexit(d, 4);
	numcheck(d);
	if (!firstandlast(d.map2[d.lines]) || !firstandlast(d.map2[0]))
		iexit(d, 4);
	d = pathcheck(d);
	d = ffcheck(d);
	return (d);
}
