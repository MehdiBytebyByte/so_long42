/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmaker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:45:51 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/21 04:48:39 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//reads the entire map in one string
t_struct mapreader(t_struct data)
{
	char	*reader;
	int 	i;

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
	return (data);
	// free(joiner);		//remmember to free checker
}
