/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:58:24 by seozkan           #+#    #+#             */
/*   Updated: 2023/01/14 14:46:20 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_putnbr(int n)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar('-');
		nbr = -n;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	sum;

	sign = 1;
	sum = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
		|| *str == '\r' || *str == '\v')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		str++;
	}
	return (sum * sign);
}
