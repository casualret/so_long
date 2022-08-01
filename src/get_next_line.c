/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsiu <thsiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:20:03 by thsiu             #+#    #+#             */
/*   Updated: 2022/02/11 17:59:40 by thsiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

static int	ft_eof_check(char *save)
{
	if (!save)
		return (0);
	while (*save)
	{
		if (*save == '\n')
			return (0);
		save++;
	}
	return (1);
}

static char	*ft_getline(char *save)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && (save[i] != '\n'))
		i++;
	dest = (char *)malloc (sizeof(char) * (i + 2));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, save, i + 2);
	if (dest[0] == '\0')
	{
		free(dest);
		return (NULL);
	}
	return (dest);
}

static char	*ft_getbuf(char *save)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && (save[i] != '\n'))
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	dest = (char *)malloc (sizeof(char) * (ft_strlen(save) - i + 1));
	if (!dest)
	{
		free(save);
		return (NULL);
	}
	ft_strlcpy(dest, &save[i + 1], (ft_strlen(save) - i + 1));
	free (save);
	return (dest);
}

static char	*ft_readline(int fd, char *buf, char *save)
{
	int		readch;
	char	*tmp;

	readch = 1;
	if (!save)
		save = ft_strdup("");
	while (readch && ft_eof_check(save))
	{
		readch = read (fd, buf, BUFFER_SIZE);
		if (readch < 0)
		{
			free(save);
			return (NULL);
		}
		buf[readch] = '\0';
		tmp = save;
		save = ft_strjoin(save, buf);
		free(tmp);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char				*buf;
	char				*line;
	static char			*save;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	save = ft_readline(fd, buf, save);
	free (buf);
	line = ft_getline(save);
	save = ft_getbuf(save);
	return (line);
}
