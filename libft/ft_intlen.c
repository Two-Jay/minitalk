/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 20:47:47 by jekim             #+#    #+#             */
/*   Updated: 2021/06/10 21:31:35 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int nbr, int base)
{
	int len;

	len = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		len++;
	}
	while (nbr > 0)
	{
		nbr = nbr / base;
		len++;
	}
	return (len);
}