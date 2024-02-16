/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmaker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:45:51 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/15 20:02:12 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//reads the entire map in one string
char	*mapreader(t_struct data)
{
	int		i;
	char	*reader;
	char	*joiner;
	char 	*map;
	
	joiner = NULL;
	i = 0;
	data.fd = open(data.name, O_RDONLY);
	while (1)
	{
		reader = get_next_line(data.fd);
		if (!reader)
			break ;	
		joiner = ft_strjoin(joiner, reader);
		free(reader);
		reader = NULL;
	}
	return (joiner);
	// map = ft_split(joiner, '\n'); in case you want to split into different strings
	// free(joiner);		//remmember to free checker
}
