/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:46:45 by jekim             #+#    #+#             */
/*   Updated: 2021/06/21 18:47:17 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../libft/libft.h"

# define _XOPEN_SOURCE 500

struct sigaction phase_read_connection;
struct sigaction phase_read_header;
struct sigaction phase_read_msg;

void	ft_clear_req_struct(void);
void	ft_pingpong_req(int signo, siginfo_t *siginfo);
int		ft_pid_print(int pid, int flag);

typedef struct		s_request
{
	pid_t			clipid;
	unsigned int	len;
	unsigned int	len_bc;
	char 			*msg;
	unsigned int	msg_ix;
	unsigned int	msg_bc;
}					t_request;

extern t_request g_request;

#endif