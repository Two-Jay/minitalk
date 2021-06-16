/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:48:12 by jekim             #+#    #+#             */
/*   Updated: 2021/06/17 00:58:10 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

t_request g_request;

static void ft_receive_header(int signo, siginfo_t *siginfo, void *context)
{
	static int ix;
	
	if (ix < 32)
	{
		if (ix == 0)
			g_request.clipid = siginfo->si_pid;
		if (g_request.clipid != 0 && g_request.clipid != siginfo->si_pid)
			ft_strerr("Error : signal interuption!");
		g_request.len <<= 1;
		g_request.len += (signo == SIGUSR2);
		ix++;
	}
	if (ix == 32)
	{
		ix = 0;
		sigaction(SIGUSR2, &phase_read_msg, 0);
		sigaction(SIGUSR1, &phase_read_msg, 0);
	}
}

// void	ft_pingpong_srv()
static void	ft_initialize_req()
{
	g_request.clipid = 0;
	g_request.len = 0;
	g_request.msg = NULL;
}

static void ft_receive_msg(int signo, siginfo_t *siginfo, void *context)
{
	static int ix;
	static int size;
	
	size = (g_request.len + 1);
	g_request.msg = (char *)malloc(sizeof(char) * size);
	if (ix < (size - 1) * 8)
	{
		*(g_request.msg) <<= 1;
		*(g_request.msg) += (signo == SIGUSR2);
		ix++;
	}
	else if (ix >= (size - 1) * 8 && ix < size * 8)
	{
		*(g_request.msg) <<= 1;
		ix++;
	}
	else if (ix == size * 8)
	{
		printf("msg == [%s]\n", g_request.msg);
		free(g_request.msg);
		ft_initialize_req();
		ix = 0;
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
