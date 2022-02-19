/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhadou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:36:58 by aouhadou          #+#    #+#             */
/*   Updated: 2022/02/17 11:38:27 by aouhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		usleep(300);
		kill(pid, (c >> i & 1) + SIGUSR1);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*s;
	int		i;

	i = 0;
	if (ac != 3)
	{
		write(1, "Invalid Arguments Please Enter Server ", 39);
		write(1, "Pid Followed By Message\n", 25);
		return (0);
	}
	else if (!(ft_isdigit(av[1])))
	{
		write(1, "Invalid Pid You Must Use Number\n", 33);
		return (0);
	}
	pid = ft_atoi(av[1]);
	s = av[2];
	while (s[i])
	{
		send_char(s[i], pid);
		i++;
	}
}
