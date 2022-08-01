/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsiu <thsiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:35:20 by thsiu             #+#    #+#             */
/*   Updated: 2022/03/18 13:49:51 by thsiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	ft_close_win(int key)
{
	(void)key;
	exit(0);
}

void	arg_read(char *map)
{
	while (*map)
		write(1, map++, 1);
	write(1, "\n", 1);
}

void	check_args(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (!(path[i - 1] == 'r' && path[i - 2] == 'e' && path[i - 3] == 'b' && \
	path[i - 4] == '.' && path[i -5] >= 48))
	{
		write(1, "check path ", 11);
		arg_read(path);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_data	*vars;

	if (argc == 2)
	{
		check_args(argv[1]);
		check_map_chars(argv[1]);
		check_map_size1(argv[1], &vars);
		read_map(argv[1], &vars);
		vars->mlx = mlx_init();
		vars->win = mlx_new_window(vars->mlx, vars->win_size.x * 64,
				vars->win_size.y * 64, "thsiu");
		mlx_hook(vars->win, 17, 0, ft_close_win, 0);
		init_map(vars->map, &vars);
		mlx_key_hook(vars->win, movement, &vars);
		mlx_loop_hook(vars->mlx, animas, (void *)&vars);
		mlx_loop(vars->mlx);
	}
	else
		ft_putstr("check your arguments!\n");
	return (0);
}
