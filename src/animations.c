/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsiu <thsiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:11:43 by thsiu             #+#    #+#             */
/*   Updated: 2022/03/14 23:15:20 by thsiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

static void	player_animation(t_data **v)
{
	static int	counter = 0;

	if (counter % 10000 == 0)
	{
		draw_in_game("./img/void.xpm", v, (*v)->player.x * 64,
			(*v)->player.y * 64);
		if ((*v)->map[(*v)->player.y][(*v)->player.x] == 'E')
			draw_in_game("./img/close_exit.xpm", v, (*v)->player.x * 64,
				(*v)->player.y * 64);
		draw_in_game("./img/player2.xpm", v, (*v)->player.x * 64,
			(*v)->player.y * 64);
		counter++;
		return ;
	}
	if (counter % 5000 == 0)
	{
		draw_in_game("./img/void.xpm", v, (*v)->player.x * 64,
			(*v)->player.y * 64);
		if ((*v)->map[(*v)->player.y][(*v)->player.x] == 'E')
			draw_in_game("./img/close_exit.xpm", v, (*v)->player.x * 64,
				(*v)->player.y * 64);
		draw_in_game("./img/player.xpm", v, (*v)->player.x * 64,
			(*v)->player.y * 64);
	}
	counter++;
}

static int	door_animation(t_data **v)
{
	int	i;
	int	j;

	i = 0;
	if ((*v)->object.collect == 0)
	{
		while ((*v)->map[++i])
		{
			j = -1;
			while ((*v)->map[i][++j])
			{
				if ((*v)->map[i][j] == 'E')
				{
					draw_in_game("./img/void.xpm", v, j * 64, i * 64);
					draw_in_game("./img/exit.xpm", v, j * 64, i * 64);
				}
			}
		}
		return (1);
	}
	return (0);
}

int	animas(t_data **vars)
{
	static int	k;

	player_animation(vars);
	if (k != 1)
		k = door_animation(vars);
	if ((*vars)->player.x == (*vars)->enemy.x
		&& (*vars)->player.y == (*vars)->enemy.y)
		exit(0);
	return (0);
}
