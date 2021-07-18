/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:48:12 by jekim             #+#    #+#             */
/*   Updated: 2021/07/18 14:10:15 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

t_request g_request;

void	ft_sigstruct_init(void)
{
	phase_read_connection.sa_sigaction = ft_receive_connection;
	phase_read_msglen.sa_sigaction = ft_receive_header;
	phase_read_msg.sa_sigaction = ft_receive_msg;
	sigemptyset(&phase_read_connection.sa_mask);
	sigemptyset(&phase_read_msglen.sa_mask);
	sigemptyset(&phase_read_msg.sa_mask);
	phase_read_connection.sa_flags = SA_SIGINFO;
	phase_read_msglen.sa_flags = SA_SIGINFO;
	phase_read_msg.sa_flags = SA_SIGINFO;
}

int		ft_pid_print(int pid, int flag)
{
	char *buf;

	buf = ft_itoa(pid);
	if (!buf)
		exit(1);
	if (flag == 1)
		write(1, "client pid : ", 13);
	else if (flag == 2)
		write(1, "server pid : ", 13);
	write(1, buf, ft_strlen(buf));
	write(1, "\n", 1);
	free(buf);
	buf = 0;
	return (0);
}

void	ft_initialize_req(void)
{
	g_request.clipid = 0;
	g_request.len = 0;
	g_request.len_bc = 0;
	g_request.msg = NULL;
	g_request.msg_ix = 0;
	g_request.msg_bc = 0;
	sigaction(SIGUSR2, &phase_read_connection, NULL);
	sigaction(SIGUSR1, &phase_read_connection, NULL);
}

int		main(void)
{
	ft_pid_print(getpid(), 2);
	ft_sigstruct_init();
	sigaction(SIGUSR2, &phase_read_connection, NULL);
	sigaction(SIGUSR1, &phase_read_connection, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
