/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 03:05:59 by jekim             #+#    #+#             */
/*   Updated: 2021/06/04 19:20:44 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(char *str)
{
	char	*ret;
	size_t	len;
	size_t	ix;

	ix = 0;
	len = ft_strlen(str);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (ix < strlen)
	{
		ret[ix] = str[ix];
		ix++;
	}
	str[ix] = '\0';
	return (ret);
}
