/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_reqsend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:15:40 by jekim             #+#    #+#             */
/*   Updated: 2021/09/28 16:26:29 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

t_request	g_request;

void	ft_bitsend(pid_t srvpid, int data, int data_size, int *idx)
{
	int		bit_mask;

	bit_mask = (1 << ((data_size * 8) - 1));
	if (((data << *idx) & bit_mask) == bit_mask)
	{
		(*idx)++;
		kill(srvpid, SIGUSR2);
	}
	else
	{
		(*idx)++;
		kill(srvpid, SIGUSR1);
	}
}

int	ft_strbit_send(pid_t srvpid, char *msg)
{
	static int	ix;
	static int	jx;

	if (ix == g_request.len)
		exit(0);
	ft_bitsend(srvpid, msg[ix], sizeof(char), &jx);
	if (jx == 8)
	{
		ix++;
		jx = 0;
	}
	return (0);
}

void	ft_receive_ping_str(int signo, siginfo_t *siginfo, void *context)
{
	(void)signo;
	(void)siginfo;
	(void)context;
	ft_strbit_send(g_request.srvpid, g_request.msg);
}

int	ft_intbit_send(pid_t srvpid, int data)
{
	static int	ix;

	if (ix < 32)
		ft_bitsend(srvpid, data, sizeof(int), &ix);
	else if (ix == 32)
	{
		sigaction(SIGUSR2, &g_request.phase_send_msg, NULL);
		sigaction(SIGUSR1, &g_request.phase_send_msg, NULL);
		ft_strbit_send(srvpid, g_request.msg);
	}
	return (0);
}

void	ft_receive_ping_len(int signo, siginfo_t *siginfo, void *context)
{
	(void)signo;
	(void)siginfo;
	(void)context;
	ft_intbit_send(g_request.srvpid, g_request.len);
}
