/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:02:18 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/17 16:44:58 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	iexit(t_struct data, int i)
{
	if (i == 1)
		printf("The name of the file should end with .ber");
	else if(i == 2)
		printf("Can't open the file or it doesn't exist");
	else if(i == 3)
		printf("The Map doesn't follow the rules of the subject");
	if(i > 3)
		{
			free(data.map);
			free(data.map2);
		}
	exit(1);
}