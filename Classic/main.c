/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:16:15 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/18 23:34:24 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_struct Datafiller(t_struct data)
{
	int i;

	i = 0;
	data.firstnl = 0;
	data.lines = 0;
	data.len = ft_strlen(data.map);
	while (data.map[data.firstnl] && data.map[data.firstnl] != '\n')
		data.firstnl++;
	while (data.map[i])
	{
		if (data.map[i] == '\n')
			data.lines++;
		i++;
	}
	data.lines++;
	data.len++;
	data.firstnl++;
	return (data);
}

//The home function for checks
t_struct Bigcheckfunc(t_struct data)
{
	namecheck(data);
	data.fd = opencheck(data);
	data = mapreader(data);
	doublenewcheck(data);
	data = Datafiller(data);
	data = shapecheck(data);
	if (!midlines(data) || !diffkeyscheck(data))
		iexit(data, 3);
	numcheck(data);
	if (!firstandlast(data.map2[data.lines - 1]) || !firstandlast(data.map2[0]))
	{
		printf("First and last");
		iexit(data, 3);
	}
	printf("%s",data.map);
	return (data);
}


int main(int argc, char *argv[])
{
	t_struct data;
	
	if(argc != 2)
		{
			printf("enter a map and nothing else");
			exit(1);
		}
	data.name = argv[1];
	data = Bigcheckfunc(data);
	printf("\nLen %d\n",data.len);
	printf("lines %d\n",data.lines);
	printf("first nl %d\n",data.firstnl);
	return 0;
}


// To do next
// Flood fill tomorrow
// set up correct error message
//Makefile
//Mlx
//remmember to protect this screen size
//in Flood Fill remmmember to protect when the collectible is Blocked by a End and versi vera
//LEAKSS Free both 2d arrays in the fail function or after program end
//when escape is pressed remmember to close and free



