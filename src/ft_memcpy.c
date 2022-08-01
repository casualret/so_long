/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsiu <thsiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:11:32 by thsiu             #+#    #+#             */
/*   Updated: 2022/03/14 21:11:34 by thsiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	*ft_memcpy(void *dest, const void *src, size_t length)
{
	char	*destbuf;

	if (!dest && !src)
		return (0);
	destbuf = dest;
	while (length-- > 0)
		*(destbuf++) = *(char *)(src++);
	return (dest);
}
