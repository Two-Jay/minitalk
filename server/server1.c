/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:25:57 by jekim             #+#    #+#             */
/*   Updated: 2021/06/16 20:41:33 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

t_request g_request;

void ft_clear_req_struct(void)
{
	g_request.len = 0;
	g_request.msg = NULL;
}

void ft_pingpong_req(int signo, siginfo_t *siginfo)
{
	if (siginfo->si_pid != g_request.clipid)
		kill(siginfo->si_pid, SIGUSR1);
	else
		kill(siginfo->si_pid, SIGUSR2);
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
