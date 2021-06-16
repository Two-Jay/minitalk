/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:46:45 by jekim             #+#    #+#             */
/*   Updated: 2021/06/16 04:11:23 by jekim            ###   ########.fr       */
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

struct sigaction phase_srv_hs;
struct sigaction phase_srv_hsheader;
struct sigaction phase_srv_request;
struct sigaction phase_srv_error;

typedef struct		s_request
{
	unsigned int	clipid;
	unsigned int	len;
	char 			*msg;
	unsigned int	clipid_bit;
	unsigned int	len_bit;
	unsigned int	msg_bit;
}					t_request;

#endif