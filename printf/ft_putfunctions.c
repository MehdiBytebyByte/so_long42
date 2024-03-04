/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:56:16 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 00:43:13 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		count++;
	}
	if (n < 10)
	{
		count += ft_putchar(n + 48);
	}
	else
	{
		count += ft_putnbr((n / 10));
		count += ft_putnbr((n % 10));
	}
	return (count);
}

int	ft_putnbr2(long n)
{
	int	count;

	count = 0;
	if (n < 10)
	{
		count += ft_putchar(n + 48);
	}
	else
	{
		count += ft_putnbr((n / 10));
		count += ft_putnbr((n % 10));
	}
	return (count);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		i = write(1, "(null)", 6);
		return (i);
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}
