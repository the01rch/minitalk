/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:51:15 by redrouic          #+#    #+#             */
/*   Updated: 2024/03/13 17:29:22 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../icl/minitalk.h"

int	g_nb = 0;

static void	print_char(int *bit)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < 8)
	{
		c += bit[i] * (1 << i);
		i++;
	}
	ft_putchar(c);
	g_nb = 0;
}

static void	client_handler(int sig, siginfo_t *info, void *context)
{
	static int	bit[8];

	(void)context;
	(void)sig;
	if (info->si_signo == SIGUSR1)
	{
		bit[g_nb] = 1;
		g_nb++;
	}
	if (info->si_signo == SIGUSR2)
	{
		bit[g_nb] = 0;
		g_nb++;
	}
	if (g_nb == 8)
	{
		print_char(bit);
		bit[0] = 0;
	}
}

static void	server(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO | SA_RESTART;
	act.sa_sigaction = (void *)client_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	ft_putstr("Waiting for client...\n");
	while (1)
		usleep(1000000);
}

int	main(int ac, char **av)
{
	(void)av;
	(void)ac;
	server();
	return (1);
}
