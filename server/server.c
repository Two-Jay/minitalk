/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:48:12 by jekim             #+#    #+#             */
/*   Updated: 2021/06/21 18:50:28 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

t_request g_request;

void ft_pingpong_req(int clipid, siginfo_t *siginfo)
{
	kill(clipid, SIGUSR2);
}

void ft_pingpong_wait(int clipid, siginfo_t *siginfo)
{
	kill(clipid, SIGUSR1);
}

int ft_pid_print(int pid, int flag)
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

static void	ft_initialize_req()
{
	g_request.clipid = 0;
	g_request.len = 0;
	g_request.len_bc = 0;
	g_request.msg = NULL;
	g_request.msg_ix = 0;
	g_request.msg_bc = 0;
	sigaction(SIGUSR2, &phase_read_header, NULL);
	sigaction(SIGUSR1, &phase_read_header, NULL);
}

static void ft_receive_header(int signo, siginfo_t *siginfo, void *context)
{
	static int tmp = 0;

	g_request.len <<= 1;
	g_request.len += (signo == SIGUSR2);
	g_request.len_bc++;
	if (g_request.len_bc == 32)
	{
		if (!g_request.msg)	
			g_request.msg = (char *)ft_calloc(sizeof(char), (g_request.len + 1));
		sigaction(SIGUSR2, &phase_read_msg, NULL);
		sigaction(SIGUSR1, &phase_read_msg, NULL);
	}
	ft_pingpong_req(g_request.clipid, siginfo);
}


static void ft_receive_msg(int signo, siginfo_t *siginfo, void *context)
{
	pid_t tmp;

	tmp = g_request.clipid;
	g_request.msg[g_request.msg_ix] <<= 1;
	g_request.msg[g_request.msg_ix] += (signo == SIGUSR2);
	g_request.msg_bc++;
	if (g_request.msg_bc == 8)
	{
		g_request.msg_ix++;
		g_request.msg_bc = 0;
	}
	if (g_request.msg_ix == g_request.len)
	{
		ft_pid_print(g_request.clipid, 1);
		write(1, g_request.msg, g_request.len);
		write(1, "\n", 1);
		free(g_request.msg);
		ft_initialize_req();
	}
	ft_pingpong_req(tmp, siginfo);
}


void ft_receive_connection(int signo, siginfo_t *siginfo, void *context)
{
	if (g_request.clipid == 0)
	{
		g_request.clipid = siginfo->si_pid;
		sigaction(SIGUSR2, &phase_read_header, NULL);
		sigaction(SIGUSR1, &phase_read_header, NULL);
		ft_pingpong_req(g_request.clipid, siginfo);
	}
	else if (g_request.clipid)
		ft_pingpong_wait(g_request.clipid, siginfo);
	else
		;
}

void ft_sigstruct_init(void)
{
	phase_read_connection.sa_sigaction = ft_receive_connection;
	phase_read_header.sa_sigaction = ft_receive_header;
	phase_read_msg.sa_sigaction = ft_receive_msg;
	sigemptyset(&phase_read_connection.sa_mask);
	sigemptyset(&phase_read_header.sa_mask);
	sigemptyset(&phase_read_msg.sa_mask);
	phase_read_connection.sa_flags = SA_SIGINFO;
	phase_read_header.sa_flags = SA_SIGINFO;
	phase_read_msg.sa_flags = SA_SIGINFO;
}

int main(int argc, char **argv)
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
