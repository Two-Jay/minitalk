/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:48:12 by jekim             #+#    #+#             */
/*   Updated: 2021/06/19 07:11:25 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

t_request g_request;

// void	ft_pingpong_srv()
static void	ft_initialize_req()
{
	g_request.clipid = 0;
	g_request.len = 0;
	g_request.len_bc = 0;
	g_request.msg = NULL;
	g_request.msg_ix = 0;
	g_request.msg_bc = 0;
}

static void ft_receive_header(int signo, siginfo_t *siginfo, void *context)
{
	g_request.clipid = siginfo->si_pid;
	g_request.len <<= (g_request.len_bc != 0);
	g_request.len += (signo == SIGUSR2);
	printf("%d", (signo == SIGUSR2));
	g_request.len_bc++;
	if (g_request.len_bc == 32)
	{
		if (!g_request.msg)	
			g_request.msg = (char *)malloc(sizeof(char) * (g_request.len + 1));
		printf("\ng_clipid == [%d]\ng_len == [%d]\n", g_request.clipid, g_request.len);
		ft_initialize_req();
		// sigaction(SIGUSR2, &phase_read_msg, 0);
		// sigaction(SIGUSR1, &phase_read_msg, 0);
	}
}


static void ft_receive_msg(int signo, siginfo_t *siginfo, void *context)
{
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
		printf("msg == [%s]\n", g_request.msg);
		free(g_request.msg);
		ft_initialize_req();
	}
}

void ft_sigstruct_init(void)
{
	phase_read_header.sa_sigaction = ft_receive_header;
	phase_read_msg.sa_sigaction = ft_receive_msg;
	sigemptyset(&phase_read_header.sa_mask);
	sigemptyset(&phase_read_msg.sa_mask);
	phase_read_header.sa_flags = SA_SIGINFO;
	phase_read_msg.sa_flags = SA_SIGINFO;
}

int main(int argc, char **argv)
{
	ft_pid_print(getpid(), 2);
	ft_sigstruct_init();
	sigaction(SIGUSR2, &phase_read_header, 0);
	sigaction(SIGUSR1, &phase_read_header, 0);
	while (1)
	{
		pause();
	}
	return (0);	
}
