/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsiu <thsiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:40:31 by thsiu             #+#    #+#             */
/*   Updated: 2022/03/18 14:43:24 by thsiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 42

typedef struct s_cords {
	int	x;
	int	y;
}	t_cords;

typedef struct s_chars {
	int	player;
	int	exit;
	int	collect;
}	t_chars;

typedef struct s_data {
	char	**map;
	void	*mlx;
	void	*win;
	t_cords	win_size;
	t_cords	player;
	t_cords	enemy;
	t_chars	object;
	int		score;
	char	*char_score;
	int		checker;
}	t_data;

// checkers
void	check_args(char *path);
void	arg_read(char *map);
void	check_map_size1(char *file, t_data **vars);
void	check_map_size2(char *line, int fd, t_data **vars);
void	check_map_chars(char *path);

// utils
int		fd_open(char *path);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t length);
void	ft_putnbr(int n);
void	ft_putchar(char c);

//gnl && itoa
char	*get_next_line(int fd);
char	*ft_itoa(int n);

//read map
void	read_map(char *file, t_data **vars);
void	init_chars(t_data **vars);
void	check_objects(t_data **vars);
void	check_walls1(t_data **vars);
void	check_walls2(t_data **vars);

//map render
void	init_map(char	**map, t_data	**vars);
void	draw(char *path, t_data **vars);
void	draw_tile(char tile, t_data **vars, int i, int j);

//movements
void	keybinds(int keycode, t_data **vars);
int		movement(int keycode, t_data **vars);
void	draw_in_game(char *path, t_data **vars, int i, int k);
void	check_move(t_data **vars, int x, int y);

//bonus
int		animas(t_data **vars);
int		ft_close_win(int key);

#endif