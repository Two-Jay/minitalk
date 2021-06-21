/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:42:20 by jekim             #+#    #+#             */
/*   Updated: 2021/06/21 22:09:34 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

t_request g_request;

void	ft_receive_ping_cnt(int signo, siginfo_t *siginfo, void *context)
{
	if (signo == SIGUSR1)
		;
	if (signo == SIGUSR2)
	{
		sigaction(SIGUSR2, &phase_send_msglen, NULL);
		sigaction(SIGUSR1, &phase_send_msglen, NULL);
		ft_intbit_send(g_request.srvpid, g_request.len);
	}
}

void	ft_send_connection(void)
{
	int			sleep_checker;

	sleep_checker = 0;
	while (1)
	{
		kill(g_request.srvpid, SIGUSR2);
		sleep_checker = usleep(500000);
		g_request.tc++;
		if (sleep_checker != 0 || g_request.tc == 31)
		{
			break ;
		}
	}
	if (g_request.tc == 31)
		ft_strerr("Error : the Server didn't receive client's request");
}

int		main(int argc, char **argv)
{
	ft_validate_input(argc, argv);
	ft_pid_print(g_request.clipid, 1);
	ft_sigstruct_init();
	sigaction(SIGUSR2, &phase_send_connection, NULL);
	sigaction(SIGUSR1, &phase_send_connection, NULL);
	ft_send_connection();
	while (1)
	{
		pause();
	}
	return (0);
}
