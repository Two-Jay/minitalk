/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:42:20 by jekim             #+#    #+#             */
/*   Updated: 2021/09/28 16:20:05 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

t_request	g_request;

void	ft_receive_ping_cnt(int signo, siginfo_t *siginfo, void *context)
{
	(void)siginfo;
	(void)context;
	if (signo == SIGUSR1)
	{
		ft_send_connection();
	}
	if (signo == SIGUSR2)
	{
		sigaction(SIGUSR2, &g_request.phase_send_msglen, NULL);
		sigaction(SIGUSR1, &g_request.phase_send_msglen, NULL);
		ft_intbit_send(g_request.srvpid, g_request.len);
	}
}

void	ft_send_connection(void)
{
	int			sleep_checker;
	static int	tc;

	sleep_checker = 0;
	tc = 0;
	while (1)
	{
		kill(g_request.srvpid, SIGUSR2);
		sleep_checker = usleep(1000000);
		tc++;
		if (sleep_checker != 0 || tc == 31)
		{
			break ;
		}
	}
	if (tc == 31)
		ft_strerr("Error\n: the Server didn't receive client's request");
}

int	main(int argc, char **argv)
{
	ft_validate_input(argc, argv);
	ft_pid_print(g_request.clipid, 1);
	ft_sigstruct_init();
	sigaction(SIGUSR2, &g_request.phase_send_connection, NULL);
	sigaction(SIGUSR1, &g_request.phase_send_connection, NULL);
	ft_send_connection();
	while (1)
	{
		pause();
	}
	return (0);
}
