/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:42:20 by jekim             #+#    #+#             */
/*   Updated: 2021/06/16 15:36:31 by jekim            ###   ########.fr       */
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
	ix = -1;
	while (++ix <= bit_shifter)
	{
		if (((data << ix) & bit_mask) == bit_mask)
			kill(srvpid, SIGUSR2);
		else
			kill(srvpid, SIGUSR1);
		usleep(1000);
	}
	return (0);
}

int main(int argc, char **argv)
{
	pid_t	srvpid;
	pid_t	clipid;
	int		msg_len;

	clipid = getpid();
	ft_pid_print(clipid, 1);
	ft_validate_input(argc, argv, &srvpid);
	msg_len = ft_strlen(argv[2]);
}