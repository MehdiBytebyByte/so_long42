/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posfinder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:10:41 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/03 19:08:28 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_struct collectioncount(t_struct data)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while (data.map[i] != '\0')
	{
		if (data.map[i] == 'C')
			count++;
		i++;
	}
	data.co_count = count;
	return (data);
}
// t_struct collectalloc(t_struct data)
// {
// 	int i;
// 	int	j;
// 	int c;
	
// 	c = 0;
// 	i = 0;
// 	data.colx = malloc(sizeof(int) * data.co_count);
// 	data.coly = malloc(sizeof(int) * data.co_count);
// 	while (data.map2[i])
// 	{
// 		j = 0;
// 		while (data.map2[i][j])
// 		{
// 			if (data.map2[i][j] == 'C')
// 			{
// 				data.colx[c] = i;
// 				data.coly[c] = j;
// 				c++;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (data);	
// }
