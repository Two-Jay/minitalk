/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:45:55 by jekim             #+#    #+#             */
/*   Updated: 2021/06/16 20:29:43 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../libft/libft.h"

int main(int argc, char **argv);

void ft_accecpt_res(int signo);
void ft_accecpt_err(int signo);
void ft_pingpong_signal(pid_t srvpid, int signo);

#endif