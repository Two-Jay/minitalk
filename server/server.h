/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:46:45 by jekim             #+#    #+#             */
/*   Updated: 2021/09/28 16:38:10 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../libft/libft.h"

# define _XOPEN_SOURCE 500

typedef struct s_request
{
	struct sigaction	phase_read_connection;
	struct sigaction	phase_read_msglen;
	struct sigaction	phase_read_msg;
	pid_t				clipid;
	unsigned int		len;
	unsigned int		len_bc;
	char				*msg;
	unsigned int		msg_ix;
	unsigned int		msg_bc;
}	t_request;

extern t_request	g_request;

void				ft_sigstruct_init(void);
int					ft_pid_print(int pid, int flag);
void				ft_initialize_req(void);
void				ft_print_msg(void);

void				ft_pingpong_req(int clipid);
void				ft_pingpong_wait(int clipid);
void				ft_receive_header(int signo, siginfo_t *siginfo,
						void *context);
void				ft_receive_msg(int signo, siginfo_t *siginfo,
						void *context);
void				ft_receive_connection(int signo, siginfo_t *siginfo,
						void *context);

#endif
