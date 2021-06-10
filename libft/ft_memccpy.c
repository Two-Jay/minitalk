/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:56:03 by jekim             #+#    #+#             */
/*   Updated: 2021/01/11 16:57:32 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	find;
	unsigned int 	ix;

	d = dst;
	s = (unsigned char *)src;
	find = c;
	ix = 0;
	if (!dst && !src)
		return (NULL);
	while (ix < n)
	{
		d[ix] = s[ix];
		if (s[ix] == find)
			return (d + (ix + 1));
		ix++;
	}
	return (NULL);
}
