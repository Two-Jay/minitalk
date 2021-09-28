/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:59:40 by jekim             #+#    #+#             */
/*   Updated: 2021/09/28 17:46:46 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

t_request	g_request;

int	ft_pid_print(int pid, int flag)
{
	char	*buf;

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

int	ft_validate_input(int argc, char **argv)
{
	if (argc != 3)
		ft_strerr("Usage\n: ./client [server_pid] [message]");
	if (!(argv[2]))
		ft_strerr("Error\n : invalid message");
	g_request.srvpid = (pid_t)ft_atoi(argv[1]);
	if (g_request.srvpid < 99)
		ft_strerr("Error\n : invalid server pid");
	g_request.len = ft_strlen(argv[2]);
	if (g_request.len <= 0)
		ft_strerr("Error\n : invalid message");
	g_request.clipid = getpid();
	g_request.msg = argv[2];
	return (0);
}

void	ft_sigstruct_init(void)
{
	g_request.phase_send_connection.sa_sigaction = ft_receive_ping_cnt;
	g_request.phase_send_msglen.sa_sigaction = ft_receive_ping_len;
	g_request.phase_send_msg.sa_sigaction = ft_receive_ping_str;
	sigemptyset(&g_request.phase_send_connection.sa_mask);
	sigemptyset(&g_request.phase_send_msglen.sa_mask);
	sigemptyset(&g_request.phase_send_msg.sa_mask);
	g_request.phase_send_connection.sa_flags = SA_SIGINFO;
	g_request.phase_send_msglen.sa_flags = SA_SIGINFO;
	g_request.phase_send_msg.sa_flags = SA_SIGINFO;
}

