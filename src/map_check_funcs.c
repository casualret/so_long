/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsiu <thsiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:08:17 by thsiu             #+#    #+#             */
/*   Updated: 2022/03/18 14:22:33 by thsiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	check_map_size1(char *file, t_data **vars)
{
	int		fd;
	char	*line;

	*vars = malloc(sizeof(t_data));
	if (!(*vars))
		return ;
	line = NULL;
	fd = fd_open(file);
	line = get_next_line(fd);
	(*vars)->win_size.x = ft_strlen(line) - 1;
	check_map_size2(line, fd, vars);
	free(line);
}

void	check_map_size2(char *line, int fd, t_data **vars)
{
	int	length;
	int	i;

	i = 0;
	while (line)
	{
		if (line != NULL)
		{
			if (line[ft_strlen(line) - 1] == '\n')
				length = ft_strlen(line) - 1;
			else
				length = ft_strlen(line);
			if ((*vars)->win_size.x != length)
			{
				ft_putstr("wrong length");
				exit(0);
			}
			line = get_next_line(fd);
			free(line);
		}
		i++;
	}
	(*vars)->win_size.y = i;
}

void	check_map_chars(char *path)
{
	int		fd;
	int		i;
	char	*line;

	line = NULL;
	fd = fd_open(path);
	while (fd > 0)
	{
		i = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		while (line[i] && line[i] != '\n')
		{
			if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] \
			!= 'E' && line[i] != 'C' && line[i] != 'A')
			{
				ft_putstr("wrong objs\n");
				exit (0);
			}
			i++;
		}
		free(line);
	}
}
