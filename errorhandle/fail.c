/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:02:18 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/06 15:31:42 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	iexit(t_struct d, int i)
{
	if (i <= 6)
		write(2, "ERROR\n", 7);
	if (i == 0)
		write(2, "Please Enter the map and only the map\n", 39);
	else if (i == 1)
		write(2, "The name of the file should end with .ber\n", 43);
	else if (i == 2)
		write(2, "Can't open the file or it doesn't exist\n", 41);
	else if (i == 3)
		write(2, "The file is empty \n", 20);
	else if (i == 4)
		write(2, "The Map doesn't follow the rules of the subject\n", 49);
	else if (i == 5)
		write(2, "the path is unreachable\n", 25);
	else if (i == 6)
		write(2, "Malloc Failled\n", 16);
	if (i > 3)
		cleaner(d);
	close (d.fd);
	exit(1);
}

void	cleaner(t_struct d)
{
	int	i;

	i = 0;
	free(d.map);
	while (i < d.lines + 1)
	{
		free(d.map2[i]);
		i++;
	}
	free(d.map2);
}
