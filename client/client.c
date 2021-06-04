/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:42:20 by jekim             #+#    #+#             */
/*   Updated: 2021/06/05 02:56:56 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

void ft_handler_SIGINT(int signal_num)
{
	write(STDOUT_FILENO, "i won't die!\n", 13);
}

int main(int argc, char **argv)
{
	int ix;

	signal(SIGINT, ft_handler_SIGINT);
	while (1)
	{
		ix = 0;
		printf("wasting your circlr on process [%d]\n time = %d\n", getpid(), ix);
		usleep(200000);
		ix++;
	}
	return (0);
}
