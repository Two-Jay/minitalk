/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 00:04:34 by jekim             #+#    #+#             */
/*   Updated: 2021/06/16 15:37:14 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

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

int	ft_reception_check(int signo)
{
	if (signo == SIGUSR1)
		return (0);
	return (0);
}