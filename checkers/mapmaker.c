/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmaker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:45:51 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 16:33:33 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_struct	mapreader(t_struct data)
{
	char	*reader;
	int		i;

	i = 0;
	data.map = NULL;
	data.fd = open(data.name, O_RDONLY);
	while (1)
	{
		reader = get_next_line(data.fd);
		if (!reader)
			break ;
		data.map = ft_strjoin(data.map, reader);
		free(reader);
		reader = NULL;
	}
	if (!data.map)
		iexit(data, 3);
	return (data);
}
