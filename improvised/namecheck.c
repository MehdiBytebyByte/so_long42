/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:16:14 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/18 21:29:40 by mboughra         ###   ########.fr       */
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
		printf("Name not valid \n");
		ft_exit(data, 1);
	}
}