/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsiu <thsiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:07:54 by thsiu             #+#    #+#             */
/*   Updated: 2022/03/14 21:22:31 by thsiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	draw(char *path, t_data **vars)
{
	void	*chr;
	int		x;
	int		y;

	x = 0;
	y = 0;
	chr = mlx_xpm_file_to_image((*vars)->mlx, path, &x, &y);
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, \
	chr, (*vars)->win_size.x, (*vars)->win_size.y);
}

void	draw_tile(char tile, t_data **vars, int i, int j)
{
	if (tile == '1')
		draw("./img/wall.xpm", vars);
	else if (tile == '0')
		draw("./img/void.xpm", vars);
	else if (tile == 'C')
	{
		draw("./img/collect.xpm", vars);
		(*vars)->object.collect += 1;
	}
	else if (tile == 'E')
		draw("./img/close_exit.xpm", vars);
	else if (tile == 'P')
	{
		(*vars)->player.x = j;
		(*vars)->player.y = i;
		draw("./img/player.xpm", vars);
	}
	else if (tile == 'A')
	{
		(*vars)->enemy.x = j;
		(*vars)->enemy.y = i;
		draw("./img/spikes.xpm", vars);
	}
}

void	init_map(char	**map, t_data	**vars)
{
	int		i;
	int		j;

	i = 0;
	(*vars)->win_size.y = 0;
	(*vars)->object.collect = 0;
	while (map[i])
	{
		(*vars)->win_size.x = 0;
		j = 0;
		while (map[i][j])
		{
			draw_tile(map[i][j], vars, i, j);
			j++;
			(*vars)->win_size.x += 64;
		}
		(*vars)->win_size.y += 64;
		i++;
	}
}
