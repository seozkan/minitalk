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

void	ft_transmit(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putnbr(g_len);
		ft_putstr(" characters successfully transmitted.\n");
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
		usleep(300);
	}
	if (j == -1)
	{
		ft_putstr("CLIENT : PID Error!\nPlease enter the correct PID.\n");
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
		send_data('\0', pid);
		g_len = i;
		signal(SIGUSR1, ft_transmit);
		while (1)
			pause();
	}
	else
		ft_putstr("CLIENT : FORMAT Error!\nPlease send as ./client <PID> <MESSAGE>\n");
}