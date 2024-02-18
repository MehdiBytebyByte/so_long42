/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:12:24 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/18 21:37:35 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_exit(t_struct data, int i)
{
	exit(1);
}

t_struct mapreader(t_struct data)
{
	char	*reader;
	int i;

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
	data.map2d = ft_split(data.map, '\n');
	return (data);
	// free(joiner);		//remmember to free checker
}


t_struct bigfunction(t_struct data)
{
	namecheck(data);
		
	return (data);
}

int main(int argc, char *argv[])
{
	t_struct data;
	if(argc != 2)
		ft_exit(data ,1);
	data.name = argv[1];
	data = bigfunction(data);
	return 0;
}