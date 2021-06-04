/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 01:02:23 by jekim             #+#    #+#             */
/*   Updated: 2021/01/11 05:18:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*ret;

	if (!src)
		return (NULL);
	if (!(ret = (char *)malloc(len + 1)))
		return (NULL);
	while (len--)
	{
		*(ret++) = src[start++];
	}
	*ret = '\0';
	return (ret);
}
