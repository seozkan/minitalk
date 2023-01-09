/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:57:41 by seozkan           #+#    #+#             */
/*   Updated: 2023/01/09 20:57:44 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_len;

void	ft_received(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "SERVER : Received  ", 20);
		ft_putnbr_fd(g_len, 1);
		write(1, " character. \n", 14);
	}
	exit (1);
}

void	send_data(char c, int pid)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void)pid;
	while (i < 8)
	{
		if (c << i & 0b10000000)
			j = kill(pid, SIGUSR1);
		else
			j = kill(pid, SIGUSR2);
		i++;
		usleep(150);
	}
	ft_error("", j);
}

int	main(int ac, char **av)
{
	int	a;
	int	i;

	i = 0;
	if (ac == 3)
	{
		a = ft_atoi(av[1]);
		while (av[2][i])
			send_data(av[2][i++], a);
		g_len = i;
		signal(SIGUSR1, ft_received);
		while (1)
			pause();
	}
	else
		write(1, "Error : Format ./client <server_pid> <message>\n", 48);
}
