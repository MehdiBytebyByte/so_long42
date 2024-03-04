/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:16:15 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 21:24:45 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	func(void)
{
	system("leaks so_long");
}

int	main(int argc, char *argv[])
{
	t_struct	d;

	atexit(func);
	d.name = argv[1];
	if (argc != 2)
		iexit(d, 0);
	d = bigcheckfunc(d);
	window(d);
	return (0);
}
