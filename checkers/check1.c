/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:00:16 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 17:46:29 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	namecheck(t_struct d)
{
	char	*suffix;
	int		i;
	int		j;

	i = 0;
	j = 0;
	suffix = ".ber";
	while (d.name[i])
		i++;
	i = i - 4;
	while (d.name[i] == suffix[j])
	{
		i++;
		j++;
	}
	if (j == 5)
		return ;
	else
		iexit(d, 1);
}

int	opencheck(t_struct d)
{
	int	fd;

	fd = open(d.name, O_RDONLY);
	if (fd < 0)
		iexit(d, 2);
	return (fd);
}
