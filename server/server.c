/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:48:12 by jekim             #+#    #+#             */
/*   Updated: 2021/06/16 15:31:00 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

static t_request g_request;

// 글로벌로 선언된 스트럭쳐는 static 임?
// 그렇다면 글로벌로 선언된 스트럭쳐의 멤버를 static 처럼 쓸려면 따로 static 처리를 해야함? 
void ft_init_request_struct(void)
{
	g_request.clipid = 0;
	g_request.clipid_bit = 0;
	g_request.len = 0;
	g_request.len_bit = 0;
	g_request.msg = NULL;
	g_request.msg_bit = 0;
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

void ft_handshake(int signo, siginfo_t *siginfo, void *ucontext)
{
	static int	hs_checker;

	if (signo == SIGUSR2)
	{
		hs_checker += 1;
		printf("%d", (signo == SIGUSR2));
	}
	if (signo == SIGUSR1)
		hs_checker = 0;
	if (hs_checker == 10)
	{
		hs_checker = 0;
		printf("\n");
	}
}

void ft_sigstruct_init(void)
{
	phase_srv_hs.sa_handler = ft_handshake;
	sigemptyset(&phase_srv_hs.sa_mask);
	phase_srv_hs.sa_flags = 0;
}



int main(int argc, char **argv)
{
	ft_pid_print(getpid(), 2);
	ft_sigstruct_init();
	sigaction(SIGUSR2, &phase_srv_hs, 0);
	sigaction(SIGUSR1, &phase_srv_hs, 0);
	while (1)
	{
		pause();
	}
	return (0);	
}
