/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:45:55 by jekim             #+#    #+#             */
/*   Updated: 2021/06/21 18:48:05 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../libft/libft.h"

struct sigaction phase_send_connection;
struct sigaction phase_send_msglen;
struct sigaction phase_send_msgchar;

typedef struct		s_request
{
	pid_t			clipid;
	pid_t			srvpid;
	unsigned int	len;
	char 			*msg;
	unsigned int	tc;
}					t_request;

extern t_request g_request;

int main(int argc, char **argv);

void ft_accecpt_res(int signo);
void ft_accecpt_err(int signo);
void ft_pingpong_cli(pid_t srvpid, int signo);

#endif