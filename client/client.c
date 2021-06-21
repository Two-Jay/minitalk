/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:42:20 by jekim             #+#    #+#             */
/*   Updated: 2021/06/21 17:06:32 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

t_request g_request;

void	ft_bitsend(pid_t srvpid, int data, int data_size, int *idx)
{
	int			bit_mask;

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

static int	ft_strbit_send(pid_t srvpid, char *msg)
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

static int	ft_intbit_send(pid_t srvpid, int data)
{
	static int	ix;

	if (ix < 32)
		ft_bitsend(srvpid, data, sizeof(int), &ix);
	else if (ix == 32)
	{
		sigaction(SIGUSR2, &phase_send_msgchar, NULL);
		sigaction(SIGUSR1, &phase_send_msgchar, NULL);
		ft_strbit_send(srvpid, g_request.msg);
	}
	return (0);
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

int ft_validate_input(int argc, char **argv)
{
	if (argc != 3)
		ft_strerr("Usage : ./client [server_pid] [message]");
	if (!(argv[2]))
		ft_strerr("Error : invalid message");
	g_request.len = ft_strlen(argv[2]);
	g_request.srvpid = (pid_t)ft_atoi(argv[1]);
	g_request.clipid = getpid();
	g_request.msg = argv[2];
	g_request.tc = 0;
	g_request.connection = 0;
	if (g_request.srvpid < 0)
		ft_strerr("Error : invalid server pid");
	return (0);
}

void ft_receive_ping_len(int signo, siginfo_t *siginfo, void *context)
{
	static int tmp = 0;

	tmp++;
	printf("len_send_count == [%d]\n", tmp);
	ft_intbit_send(g_request.srvpid, g_request.len);
}

void ft_receive_ping_str(int signo, siginfo_t *siginfo, void *context)
{
	static int tmp = 0;

	tmp++;
	printf("str_send_count == [%d]\n", tmp);
	ft_strbit_send(g_request.srvpid, g_request.msg);
}

void ft_receive_ping_cnt(int signo, siginfo_t *siginfo, void *context)
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

void ft_sigstruct_init(void)
{
	phase_send_connection.sa_sigaction = ft_receive_ping_cnt;
	phase_send_msglen.sa_sigaction = ft_receive_ping_len;
	phase_send_msgchar.sa_sigaction = ft_receive_ping_str;
	sigemptyset(&phase_send_connection.sa_mask);
	sigemptyset(&phase_send_msglen.sa_mask);
	sigemptyset(&phase_send_msgchar.sa_mask);
	phase_send_connection.sa_flags = SA_SIGINFO;
	phase_send_msglen.sa_flags = SA_SIGINFO;
	phase_send_msgchar.sa_flags = SA_SIGINFO;
}


// tc break ok
// but didn't send len_bit after send 1 len bit 
void ft_send_connection(void)
{
	static int tmp = 0;
	int sleep_checker;

	sleep_checker = 0;
	while (1)
	{
		printf("connection init! [%d]\n", ++tmp);	
		kill(g_request.srvpid, SIGUSR2);
		sleep_checker = usleep(1000000);
		g_request.tc++;
		if (sleep_checker != 0 || g_request.tc == 31)
		{
			if (g_request.tc < 31)
				g_request.connection++;
			break;
		}
	}
	if (g_request.tc == 61)
		ft_strerr("Error : the Server didn't receive client's request");
}

int main(int argc, char **argv)
{
	ft_validate_input(argc, argv);
	ft_pid_print(g_request.clipid, 1);
	ft_sigstruct_init();
	sigaction(SIGUSR2, &phase_send_connection, NULL);
	sigaction(SIGUSR1, &phase_send_connection, NULL);
	ft_send_connection();
	while(1)
	{
		pause();
	}
	return (0);
}
