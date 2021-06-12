/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:42:20 by jekim             #+#    #+#             */
/*   Updated: 2021/06/12 10:31:43 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

static int	ft_kill_errh(int pid, int signo)
{
	if (kill(pid, signo) == -1)
		ft_strerr("Error : kill error");
}

// int ft_send_cli_pid()
// int ft_send_msg_length()
static int	ft_send_msg_proto(int pid, char *msg)
{
	int ix;
	int temp;
	int bit_mask;

	bit_mask = 1;
	while (*msg)
	{
		ix = 0;
		while (ix < 8)
		{
			if ((*msg & bit_mask) == 1)
				ft_kill_errh(pid, SIGUSR2);
			else
				ft_kill_errh(pid, SIGUSR1);
			*msg >>= 1;
			ix++;
		}
		msg++;
	}
	return (0);
}

int ft_pidprint(int pid)
{
	char	*buf;

	buf = ft_itoa(pid);
	if (!buf)
		exit(1);
	write(1, "client pid : ", 13);
	write(1, buf, ft_intlen(pid, 10));
	write(1, "\n", 1);
	return (0);
}

int ft_validate_input(int argc, char **argv, int *pid)
{
	if (argc != 3)
		ft_strerr("Usage : ./client [server_pid] [message]");
	if (!(argv[2]))
		ft_strerr("Error : invalid message");
	*pid = ft_atoi(argv[1]);
	if (*pid < 0)
		ft_strerr("Error : invalid server pid");
	return (0);
}

int main(int argc, char **argv)
{
	int server_pid;
	int client_pid;

	client_pid = getpid();
	ft_validate_input(argc, argv, &server_pid);
	ft_pidprint(client_pid);
	ft_send_msg_proto(server_pid, argv[2]);
}
