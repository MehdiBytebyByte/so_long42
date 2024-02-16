/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:00:16 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/15 19:45:51 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void namecheck(char *name)
{
    
  	char	*suffix;
	int		i;
	int		j;

	i = 0;
	j = 0;
	suffix	= ".ber";
	while(name[i])
		i++;
	i = i - 4;
	while (name[i] == suffix[j])
	{
		i++;
		j++;
	}
	if (j == 5)
		return ;
	printf("invalid map");
	exit(1);
}

int	opencheck(t_struct data)
{
	int fd;
	
	fd = open(data.name, O_RDONLY);
	if (fd < 0)
	{
		printf("Can't open");
		exit(1);	
	}
	return (fd);
}