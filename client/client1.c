/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:15:40 by jekim             #+#    #+#             */
/*   Updated: 2021/06/16 23:31:20 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

void ft_accecpt_res(int signo)
{
    return ;
}

void ft_accecpt_err(int signo)
{
    ft_strerr("Error : invalid response");
}

void ft_pingpong_cli(pid_t srvpid, int signo)
{
	kill(srvpid, signo);
	pause();
}