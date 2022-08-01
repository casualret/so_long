/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsiu <thsiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:39:07 by thsiu             #+#    #+#             */
/*   Updated: 2022/03/18 12:53:16 by thsiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	read_map(char *file, t_data **vars)
{
	int	fd;
	int	i;

	(*vars)->score = 0;
	i = 0;
	(*vars)->map = NULL;
	(*vars)->map = malloc(sizeof(t_data) * (*vars)->win_size.y);
	if (!(*vars)->map)
		return ;
	fd = fd_open(file);
	(*vars)->map[i] = get_next_line(fd);
	while ((*vars)->map[i])
	{
		i++;
		(*vars)->map[i] = get_next_line(fd);
	}
	(*vars)->object.player = 0;
	(*vars)->object.exit = 0;
	init_chars(vars);
}

void	init_chars(t_data **vars)
{
	int	i;
	int	j;

	i = 0;
	while ((*vars)->map[i])
	{
		j = 0;
		while ((*vars)->map[i][j])
		{
			if ((*vars)->map[i][j] == 'P')
				(*vars)->object.player += 1;
			if ((*vars)->map[i][j] == 'E')
				(*vars)->object.exit += 1;
			if ((*vars)->map[i][j] == 'C')
				(*vars)->object.collect += 1;
			j++;
		}
		i++;
	}
	check_objects(vars);
}

void	check_objects(t_data **vars)
{
	if ((*vars)->object.exit <= 0 || (*vars)->object.collect <= 0)
	{
		ft_putstr("wrong number of exits or collectibles\n");
		exit(0);
	}
	if ((*vars)->object.player != 1)
	{
		ft_putstr("wrong number of player\n");
		exit(0);
	}
	write(1, "\n", 1);
	check_walls1(vars);
}

void	check_walls1(t_data **vars)
{
	int	i;
	int	j;

	i = 0;
	while ((*vars)->map[i])
	{
		j = 0;
		while ((*vars)->map[i][j] != '\n' && \
		(*vars)->map[i][j] != 0)
		{
			if ((*vars)->map[0][j] != '1' || \
			(*vars)->map[(*vars)->win_size.y - 1][j] != '1')
			{
				ft_putstr("wrong walls\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
	check_walls2(vars);
}

void	check_walls2(t_data **vars)
{
	int	i;
	int	j;

	i = 0;
	while ((*vars)->map[i])
	{
		j = 0;
		while ((*vars)->map[i][j])
		{
			if ((*vars)->map[i][(*vars)->win_size.x - 1] != '1')
			{
				ft_putstr("wrong walls\n");
				exit(0);
			}
			if ((*vars)->map[i][0] != '1')
			{
				ft_putstr("wrong walls\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}
