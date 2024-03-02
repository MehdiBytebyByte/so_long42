/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   homecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:56:43 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/02 15:22:23 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_struct Bigcheckfunc(t_struct data)
{
	namecheck(data);
	data.fd = opencheck(data);  //open the file --- remmember to close the fd;
	data = mapreader(data);		//reads the entire map in one d array remmember to free;
	data = doublenewcheck(data); // check for the case of two conescutive newlines cuz it makes of split segfault
	data = Datafiller(data);	// fill data for use later
	data = shapecheck(data);
	if (!midlines(data) || !diffkeyscheck(data))
		iexit(data, 4);
	numcheck(data);
	if (!firstandlast(data.map2[data.lines]) || !firstandlast(data.map2[0]))
		iexit(data , 4);
	data = pathcheck(data);
	data = FFcheck(data);
	// data = collectioncount(data);
	// data = collectalloc(data);
	return (data);
}