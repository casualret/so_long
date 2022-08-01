/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsiu <thsiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:37:43 by thsiu             #+#    #+#             */
/*   Updated: 2022/02/11 16:38:13 by thsiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	char	*destbuf;

	if (s1 != 0 && s2 != 0)
	{
		dest = (char *)malloc(sizeof(char)
				* (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (dest != 0)
		{
			destbuf = dest;
			while (*s1 != 0)
				*destbuf++ = *s1++;
			while (*s2 != 0)
				*destbuf++ = *s2++;
			*destbuf++ = '\0';
			return (dest);
		}
	}
	return (0);
}
