/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 01:02:49 by jekim             #+#    #+#             */
/*   Updated: 2021/01/11 14:52:55 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_checkix(char const *s1, char const *set, int drc)
{
	unsigned int	ret;

	ret = 0;
	if (!s1 || !set || !drc)
		return (0);
	if (drc == 1)
	{
		while (*set && *s1 == *(set + ret))
			ret++;
	}
	else if (drc == -1)
	{
		ret = ft_strlen(set);
		while (*set && *s1 == *(set + ret))
			ret--;
	}
	return (ret);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char			*ret;
	unsigned int	i;
	unsigned int	left_ix;
	unsigned int	right_ix;

	if (!*s1 || !s1 || !*set || !set)
		return (NULL);
	left_ix = ft_checkix(s1, set, 1);
	right_ix = ft_checkix(s1, set, -1);
	i = 0;
	if (!(ret = (char *)malloc(right_ix - left_ix + 1)))
		return (NULL);
	while (i < (right_ix - left_ix))
	{
		*(ret++) = set[left_ix + i];
		i++;
	}
	*ret = '\0';
	return (ret);
}
