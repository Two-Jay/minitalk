/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 22:46:41 by jekim             #+#    #+#             */
/*   Updated: 2021/01/11 05:16:04 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *src, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	ix;
	unsigned int	size;

	if (!src || !f)
		return (NULL);
	ix = 0;
	size = ft_strlen(src);
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (src[ix])
	{
		ret[ix] = (*f)(ix, src[ix]);
		ix++;
	}
	return (ret);
}
