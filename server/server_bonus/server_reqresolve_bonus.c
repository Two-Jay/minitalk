/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_reqresolve_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:13:33 by jekim             #+#    #+#             */
/*   Updated: 2021/07/18 14:19:24 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./server_bonus.h"

t_request g_request;

void	ft_pingpong_req(int clipid)
{
	kill(clipid, SIGUSR2);
}

void	ft_pingpong_wait(int clipid)
{
	kill(clipid, SIGUSR1);
}

void	ft_receive_header(int signo, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (siginfo->si_pid != g_request.clipid)
		ft_pingpong_wait(siginfo->si_pid);
	else
	{
		g_request.len <<= 1;
		g_request.len += (signo == SIGUSR2);
		g_request.len_bc++;
		if (g_request.len_bc == 32)
		{
			if (!g_request.msg)
				g_request.msg = (char *)ft_calloc(sizeof(char),
					(g_request.len + 1));
			sigaction(SIGUSR2, &phase_read_msg, NULL);
			sigaction(SIGUSR1, &phase_read_msg, NULL);
		}
		ft_pingpong_req(g_request.clipid);
	}
}

void	ft_receive_msg(int signo, siginfo_t *siginfo, void *context)
{
	pid_t tmp;

	(void)context;
	if (siginfo->si_pid != g_request.clipid)
		ft_pingpong_wait(siginfo->si_pid);
	else
	{
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
		ft_pingpong_req(tmp);
	}
}

void	ft_receive_connection(int signo, siginfo_t *siginfo, void *context)
{
	(void)signo;
	(void)context;
	if (g_request.clipid == 0)
	{
		g_request.clipid = siginfo->si_pid;
		sigaction(SIGUSR2, &phase_read_msglen, NULL);
		sigaction(SIGUSR1, &phase_read_msglen, NULL);
		ft_pingpong_req(g_request.clipid);
	}
	else if (g_request.clipid)
		ft_pingpong_wait(g_request.clipid);
}
