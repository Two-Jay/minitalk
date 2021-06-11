/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:48:12 by jekim             #+#    #+#             */
/*   Updated: 2021/06/12 00:41:27 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

int ft_pidprint(int pid)
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

int main(int argc, char **argv)
{
	ft_pidprint(getpid());
	// get client_pid
	// get msg lenght
	// get msg and write
	// 
	return (0);	
}
