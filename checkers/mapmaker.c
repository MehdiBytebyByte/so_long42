/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmaker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:45:51 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 17:46:29 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_struct	mapreader(t_struct d)
{
	char	*reader;
	int		i;

	i = 0;
	d.map = NULL;
	d.fd = open(d.name, O_RDONLY);
	while (1)
	{
		reader = get_next_line(d.fd);
		if (!reader)
			break ;
		d.map = ft_strjoin(d.map, reader);
		free(reader);
		reader = NULL;
	}
	if (!d.map)
		iexit(d, 3);
	return (d);
}
