/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:42:20 by jekim             #+#    #+#             */
/*   Updated: 2021/06/11 22:30:36 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

int ft_validate_input(argc, argv, int *pid)
{
	if (argc != 3)
		ft_strerr("Usage");
	if (argv[2][0])
		ft_strerr("invalid msg");
	*pid = ft_atoi(argv[1]);
	if (*pid < 0)
		ft_strerr("invalid pid");
}

int main(int argc, char **argv)
{
	int server_pid;
	int client_pid;

	client_pid = getpid();
	ft_validate_input(argc, argv, &server_pid);
	return (0);
}
