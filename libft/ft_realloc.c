/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 02:39:48 by jekim             #+#    #+#             */
/*   Updated: 2021/05/30 03:21:24 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_memlen(void *ptr)
{
	unsigned char	*target;
	size_t			ret;

	if (ptr && !(unsigned char *)ptr)
		return (0);
	ret = 0;
	target = (unsigned char *)ptr;
	while (*target)
	{
		ret++;
	}
	return (ret);
}

static void		*ft_realloc_subfunc(void *src, void *ret,
			size_t copy_size, size_t malloc_size)
{
	ret = malloc(malloc_size);
	ft_memmove(ret, src, copy_size);
	free(src);
	return (ret);
}

void			*ft_realloc(void *src, size_t size)
{
	void	*ret;
	size_t	srcsize;

	ret = NULL;
	srcsize = ft_memlen(src);
	if (!src && !size)
		return (NULL);
	if (!src && size)
	{
		ret = malloc(size);
		return (ret);
	}
	if (ft_memlen(src) > size)
		ft_realloc_subfunc(src, ret, size, size);
	else if (ft_memlen(src) < size)
		ft_realloc_subfunc(src, ret, srcsize, size);
	else
		ft_realloc_subfunc(src, ret, srcsize, srcsize);
	return (ret);
}
