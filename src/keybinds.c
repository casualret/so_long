/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsiu <thsiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:34:06 by thsiu             #+#    #+#             */
/*   Updated: 2022/03/14 23:15:42 by thsiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	draw_in_game(char *path, t_data **vars, int i, int k)
{
	void	*chr;
	int		x;
	int		y;

	x = 0;
	y = 0;
	chr = mlx_xpm_file_to_image((*vars)->mlx, path, &x, &y);
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, chr, i, k);
}

void	check_move(t_data **vars, int x, int y)
{
	(*vars)->checker = 1;
	if ((*vars)->map[(*vars)->player.y + y][(*vars)->player.x + x] == '1')
		(*vars)->checker = 0;
	if ((*vars)->map[(*vars)->player.y + y][(*vars)->player.x + x] == 'C')
	{
		(*vars)->map[(*vars)->player.y + y][(*vars)->player.x + x] = '0';
		(*vars)->object.collect--;
	}
}

void	keybinds(int keycode, t_data **vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (keycode == 13 || keycode == 126)
		y--;
	else if (keycode == 1 || keycode == 125)
		y++;
	else if (keycode == 0 || keycode == 123)
		x--;
	else if (keycode == 2 || keycode == 124)
		x++;
	check_move(vars, x, y);
	if ((*vars)->checker == 1)
	{
		draw_in_game("./img/void.xpm", vars, ((*vars)->player.x * 64), (
				(*vars)->player.y * 64));
		if ((*vars)->map[(*vars)->player.y][(*vars)->player.x] == 'E')
			draw_in_game("./img/close_exit.xpm", vars, ((*vars)->player.x * 64),
				((*vars)->player.y * 64));
		(*vars)->player.x += x;
		(*vars)->player.y += y;
	}
}

int	movement(int keycode, t_data **vars)
{
	if (keycode == 53)
		exit(0);
	keybinds(keycode, vars);
	if ((*vars)->checker == 1)
	{
		(*vars)->char_score = ft_itoa(++((*vars)->score));
		write(1, "\n", 1);
		ft_putnbr((*vars)->score);
		draw_in_game("./img/wall.xpm", vars, 0, 0);
		mlx_string_put((*vars)->mlx, (*vars)->win, 16, 16,
			0xFFFFFF, (*vars)->char_score);
		free((*vars)->char_score);
		draw_in_game("./img/player.xpm", vars, ((*vars)->player.x * 64), (
				(*vars)->player.y * 64));
	}
	if ((*vars)->map[(*vars)->player.y][(*vars)->player.x] == 'E' &&
			(*vars)->object.collect == 0)
		exit(0);
	return (0);
}
