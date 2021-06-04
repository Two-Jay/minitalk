/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:09:51 by jekim             #+#    #+#             */
/*   Updated: 2021/01/12 00:45:59 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t src_l;
	size_t ix;

	if (!dst || !src || !dstsize)
		return (0);
	ix = 0;
	src_l = ft_strlen(src);
	while (src[ix] && ix + 1 < dstsize && ix < src_l)
	{
		dst[ix] = src[ix];
		ix++;
	}
	if (dstsize > 0)
		dst[ix] = '\0';
	return (src_l);
}
