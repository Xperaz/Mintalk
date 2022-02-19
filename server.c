/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhadou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:31:25 by aouhadou          #+#    #+#             */
/*   Updated: 2022/02/17 11:32:00 by aouhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	reset(int pid)
{
	t_recieved.n = 0;
	t_recieved.c = 0;
	t_recieved.pid = pid;
}

void	handler(int sig, siginfo_t *info, void *context)
{
	(void) context;
	if (t_recieved.pid != info->si_pid)
		reset(info->si_pid);
	t_recieved.c = t_recieved.c << 1 | (sig - 30);
	t_recieved.n++;
	if (t_recieved.n == 8)
	{
		write(1, &t_recieved.c, 1);
		t_recieved.n = 0;
		t_recieved.c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	t_recieved.pid = 0;
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		pause();
	}
}
