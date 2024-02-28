/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:16:15 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/28 15:10:16 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	t_struct data;
	
	// data = isetonull(data);
	data.name = argv[1];
	if(argc != 2)
		iexit(data, 0);
	data = Bigcheckfunc(data);
	if(window(data) < 0)
		iexit(data, 7);
	return 0;
}
 