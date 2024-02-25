/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:16:15 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/25 20:23:32 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_struct Datafiller(t_struct data)
{
	int i;

	i = 0;
	data.colums = 0;
	data.lines = 0;
	data.len = ft_strlen(data.map);
	while (data.map[data.colums] && data.map[data.colums] != '\n')
		data.colums++;
	while (data.map[i])
	{
		if (data.map[i] == '\n')
			data.lines++;
		i++;
	}
	printf("%d\n",data.lines);
	printf("%d\n",data.colums);
	printf("%d\n",data.len);
	return (data);
}

t_struct Bigcheckfunc(t_struct data)
{
	namecheck(data);
	data.fd = opencheck(data);  //open the file --- remmember to close the fd;
	data = mapreader(data);		//reads the entire map in one d array remmember to free;
	data = doublenewcheck(data); // check for the case of two conescutive newlines cuz it makes of split segfault
	data = Datafiller(data);	// fill data for use later
	data = shapecheck(data);
	if (!midlines(data) || !diffkeyscheck(data))
		iexit(data, 3);
	numcheck(data);
	if (!firstandlast(data.map2[data.lines]) || !firstandlast(data.map2[0]))
		iexit(data , 3);

	return (data);
}


int main(int argc, char *argv[])
{
	t_struct data;
	
	data.name = argv[1];
	if(argc != 2)
		iexit(data, 0);
	data = Bigcheckfunc(data);
	data = pathcheck(data);
	

	
	exit(1);

	return 0;
}


// To do next
// find weird segfault
// Flood fill tomorrow
// set up correct error message
//Makefile
//Mlx
//remmember to protect this screen size
//in Flood Fill remmmember to protect when the collectible is Blocked by a End and versi vera
//LEAKSS Free both 2d arrays in the fail function or after program end
//when escape is pressed remmember to close and free
 