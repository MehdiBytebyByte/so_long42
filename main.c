/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:16:15 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/16 19:03:44 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//The home function for checks
t_struct Bigcheckfunc(t_struct data)
{
	namecheck(data.name);
	data.fd = opencheck(data);
	data = mapreader(data);
	data = shapecheck(data);
	numcheck(data);
	// if (!firstandlast(data.map2[data.lines - 1]) || !firstandlast(data.map2[0]))
 	// {
	// 	printf("Error in the map");
	// 	exit(1);
	// }
	return (data);
}


int main(int argc, char *argv[])
{
	t_struct data;
	
	if(argc != 2)
		{
			printf("Enter a map and nothing else");
			exit(1);
		}
	data.name = argv[1];
	data = Bigcheckfunc(data);	
	return 0;
}
