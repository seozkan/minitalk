/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:57:34 by seozkan           #+#    #+#             */
/*   Updated: 2023/01/09 20:57:46 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_data(char c, int pid)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 8)
	{
		if (c << i & 0b10000000)
			j = kill(pid, SIGUSR1);
		else
			j = kill(pid, SIGUSR2);
		i++;
		usleep(300);
	}
	if (j == -1)
	{
		ft_putstr("CLIENT : PID Error!\nPlease enter the correct PID\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
			send_data(av[2][i++], pid);
	}
	else
		ft_putstr("CLIENT : FORMAT Error!\nPlease send as ./client <PID> <MESSAGE>\n");
}
