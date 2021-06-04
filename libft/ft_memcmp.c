/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 23:31:23 by jekim             #+#    #+#             */
/*   Updated: 2021/01/11 18:18:16 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)ptr1;
	s2 = (unsigned char *)ptr2;
	if ((!ptr1 && !ptr2) || !n)
		return (0);
	while ((*s1 == *s2) && n-- != 0)
	{
		s1++;
		s2++;
	}
	return (n == 0 ? 0 : *s1 - *s2);
}
