/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:00:16 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/24 18:34:10 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void namecheck(t_struct data)
{
  	char	*suffix;
	int		i;
	int		j;

	i = 0;
	j = 0;
	suffix	= ".ber";
	while(data.name[i])
		i++;
	i = i - 4;
	while (data.name[i] == suffix[j])
	{
		i++;
		j++;
	}
	if (j != 5)
	{
		iexit(data, 1);	
	}
}

int	opencheck(t_struct data)
{
	int fd;
	
	fd = open(data.name, O_RDONLY);
	if (fd < 0)
		iexit(data ,2);
	return (fd);
}