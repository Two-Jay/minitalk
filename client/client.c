/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:42:20 by jekim             #+#    #+#             */
/*   Updated: 2021/06/19 13:55:08 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

static int	ft_intbit_send(pid_t srvpid, int data)
{
	int			bit_mask;
	int			bit_shifter;
	int			ix;

	bit_shifter = (sizeof(int) * 8) - 1;
	bit_mask = (1 << bit_shifter);
	ix = 0;
	while (ix <= bit_shifter)
	{
		usleep(40);
		if (((data << ix) & bit_mask) == bit_mask)
			kill(srvpid, SIGUSR2);
		else
			kill(srvpid, SIGUSR1);
		ix++;
	}
	usleep(200);
	return (0);
}

static int	ft_strbit_send(pid_t srvpid, char *msg)
{
	int			bit_mask;
	int			bit_shifter;
	int			ix;
	int			jx;
	
	bit_shifter = (sizeof(char) * 8) - 1;
	bit_mask = (1 << bit_shifter);
	ix = 0;

	while (msg[ix])
	{
		jx = 0;
		while (jx <= bit_shifter)
		{
			usleep(200);
			if (((msg[ix] << jx) & bit_mask) == bit_mask)
				kill(srvpid, SIGUSR2);
			else
				kill(srvpid, SIGUSR1);
			jx++;
		}
		printf("\n");
		ix++;
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

int ft_validate_input(int argc, char **argv, pid_t *pid, int *len)
{
	if (argc != 3)
		ft_strerr("Usage : ./client [server_pid] [message]");
	if (!(argv[2]))
		ft_strerr("Error : invalid message");
	*len = ft_strlen(argv[2]);
	*pid = (pid_t)ft_atoi(argv[1]);
	if (*pid < 0)
		ft_strerr("Error : invalid server pid");
	return (0);
}

int main(int argc, char **argv)
{
	pid_t	srvpid;
	pid_t	clipid;
	int		msg_len;

	clipid = getpid();
	ft_pid_print(clipid, 1);
	ft_validate_input(argc, argv, &srvpid, &msg_len);
	ft_intbit_send(srvpid, msg_len);
	ft_strbit_send(srvpid, argv[2]);
}
