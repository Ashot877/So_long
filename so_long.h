/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 19:07:32 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/05/31 19:07:34 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "minilibx-linux/mlx.h"

typedef struct s_check
{
	int	coin;
	int	total_coin;
	int	exit_found;
}	t_check;

typedef struct s_map
{
	int		length;
	int		hight;
	char	**map;
	int		coin;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		steps;
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_coin;
	void	*img_exit;
	int		img_width;
	int		img_height;
}	t_m;

int		close_window(t_m *st);
//check_map.c
void	check_map(t_m *st);
//utils.c
char	**copy_map(char **map, int hight);
void	init_map(t_m *st);
void	read_map_lines(t_m *st, int fd);
int		size_map_help(int fd, t_m *st, int size_x_prev);
void	update_position(t_m *st, int new_x, int new_y);
//check_paths.c
void	check_paths(t_m *st);
//free_.c
void	free_st_map(t_m *st);
//fill_map.c
void	fill_st(char *argv, t_m *st);
char	*str_clear(char *str, t_m *st);
//error_.c
void	error_(t_m *map);
//mlx_func.c
void	load_images(t_m *st);
void	draw_map(t_m *st);
void	draw_tile(t_m *st, int x, int y);
//so_long.c
void	move_player(t_m *st, int dx, int dy);

#endif
