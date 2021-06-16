/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 21:31:47 by jekim             #+#    #+#             */
/*   Updated: 2021/06/16 15:56:41 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*ret;
	int		ix;

	ix = ft_intlen(n, 10);
	if (!(ret = (char *)malloc(sizeof(char) * (ix + 1))))
		return (NULL);
	ret[ix--] = '\0';
	if (n == 0)
	{
		*ret = '0';
		return (ret);
	}
	if (n < 0)
	{
		*ret = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		*(ret + ix--) = '0' + (n % 10);
		n = n / 10;
	}
	return (ret);
}
