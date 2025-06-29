/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:49:08 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/06/05 17:49:10 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window_helper(t_m *st)
{
	free_st_map(st);
	if (st->img_wall)
		mlx_destroy_image(st->mlx, st->img_wall);
	if (st->img_player)
		mlx_destroy_image(st->mlx, st->img_player);
	if (st->img_floor)
		mlx_destroy_image(st->mlx, st->img_floor);
	if (st->img_exit)
		mlx_destroy_image(st->mlx, st->img_exit);
	if (st->img_coin)
		mlx_destroy_image(st->mlx, st->img_coin);
	mlx_destroy_window(st->mlx, st->win);
	mlx_destroy_display(st->mlx);
	if (st->mlx)
	{
		free(st->mlx);
		st->mlx = NULL;
	}
}

void	load_images(t_m *st)
{
	st->img_wall = mlx_xpm_file_to_image(st->mlx, "xpm/wall.xpm",
			&st->img_width, &st->img_height);
	st->img_floor = mlx_xpm_file_to_image(st->mlx, "xpm/back.xpm",
			&st->img_width, &st->img_height);
	st->img_player = mlx_xpm_file_to_image(st->mlx, "xpm/player.xpm",
			&st->img_width, &st->img_height);
	st->img_coin = mlx_xpm_file_to_image(st->mlx, "xpm/coin.xpm",
			&st->img_width, &st->img_height);
	st->img_exit = mlx_xpm_file_to_image(st->mlx, "xpm/exit.xpm",
			&st->img_width, &st->img_height);
	if (!st->img_wall || !st->img_floor || !st->img_player
		|| !st->img_coin || !st->img_exit)
	{
		close_window_helper(st);
		error_(st);
	}
}

void	draw_map(t_m *st)
{
	int	y;
	int	x;

	y = 0;
	while (y < st->hight)
	{
		x = 0;
		while (x < st->length)
		{
			draw_tile(st, x, y);
			x++;
		}
		y++;
	}
}

void	draw_tile(t_m *st, int x, int y)
{
	char	tile;
	void	*img;

	tile = st->map[y][x];
	if (tile == '1')
		img = st->img_wall;
	else
		img = st->img_floor;
	mlx_put_image_to_window(st->mlx, st->win, img, x * 64, y * 64);
	if (tile == 'P')
		mlx_put_image_to_window(st->mlx, st->win,
			st->img_player, x * 64, y * 64);
	else if (tile == 'C')
		mlx_put_image_to_window(st->mlx, st->win, st->img_coin, x * 64, y * 64);
	else if (tile == 'E')
		mlx_put_image_to_window(st->mlx, st->win, st->img_exit, x * 64, y * 64);
}
