/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:48:12 by jekim             #+#    #+#             */
/*   Updated: 2021/06/12 11:17:28 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

static int ft_pidprint(int pid)
{
	char	*buf;

	buf = ft_itoa(pid);
	if (!buf)
		exit(1);
	write(1, "server pid : ", 13);
	write(1, buf, ft_intlen(pid, 10));
	write(1, "\n", 1);
	return (0);
}

static void ft_receive_msg(int signo)
{
	if (signo == SIGUSR2)
		write(1, "1", 1);
	else
		write(1, "0", 1);
	return (0);
}

int main(int argc, char **argv)
{
	ft_pidprint(getpid());
	signal(SIGUSR2, ft_receive_msg);
	signal(SIGUSR1, ft_receive_msg);
	while (1)
	{
		pause();
	}
	return (0);	
}
