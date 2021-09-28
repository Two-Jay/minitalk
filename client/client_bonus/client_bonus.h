/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:45:55 by jekim             #+#    #+#             */
/*   Updated: 2021/09/28 16:27:13 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../../libft/libft.h"

typedef struct s_request
{
	struct sigaction	phase_send_connection;
	struct sigaction	phase_send_msglen;
	struct sigaction	phase_send_msg;
	pid_t				clipid;
	pid_t				srvpid;
	int					len;
	char				*msg;
}	t_request;

extern t_request	g_request;

int					main(int argc, char **argv);
void				ft_send_connection(void);
void				ft_receive_ping_cnt(int signo, siginfo_t *siginfo,
						void *context);

int					ft_pid_print(int pid, int flag);
void				ft_sigstruct_init(void);
int					ft_validate_input(int argc, char **argv);

void				ft_bitsend(pid_t srvpid, int data, int data_size,
						int *idx);
int					ft_strbit_send(pid_t srvpid, char *msg);
void				ft_receive_ping_str(int signo, siginfo_t *siginfo,
						void *context);
int					ft_intbit_send(pid_t srvpid, int data);
void				ft_receive_ping_len(int signo, siginfo_t *siginfo,
						void *context);

#endif
