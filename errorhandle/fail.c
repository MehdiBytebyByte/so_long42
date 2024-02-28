/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:02:18 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/28 15:15:30 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	iexit(t_struct data, int i)
{
	write(2,"ERROR\n",7);
	if (i == 0)
		write(2,"Please Enter the map and only the map",38);
	else if (i == 1)
		write(2,"The name of the file should end with .ber",42);
	else if(i == 2)
		write(2,"Can't open the file or it doesn't exist",40);
	else if(i == 3)
		write(2,"The file is empty \n",20);
	else if(i == 4)
		write(2,"The Map doesn't follow the rules of the subject",48);
	else if(i == 4)
		write(2,"the path is unreachable",24);
	else if(i == 7)
		write(2,"mlx",4);
	data.px = 1;
	

	exit(1);

}