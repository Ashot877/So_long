/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:41:39 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/05/31 18:41:42 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_argv(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (len < 4)
	{
		ft_printf("Error\n");
		exit(2);
	}
	if (s[len - 4] != '.' || s[len - 3] != 'b'
		|| s[len - 2] != 'e' || s[len - 1] != 'r')
	{
		ft_printf("Error\n");
		exit(2);
	}
}

int	close_window(t_m *st)
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
	exit(0);
	return (0);
}

int	handle_key(int keycode, t_m *st)
{
	if (keycode == 65307)
	{
		close_window(st);
	}
	else if (keycode == 119)
		move_player(st, 0, -1);
	else if (keycode == 115)
		move_player(st, 0, 1);
	else if (keycode == 97)
		move_player(st, -1, 0);
	else if (keycode == 100)
		move_player(st, 1, 0);
	return (0);
}

void	move_player(t_m *st, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	next_tile;

	new_x = st->player_x + dx;
	new_y = st->player_y + dy;
	next_tile = st->map[new_y][new_x];
	if (next_tile == '1')
		return ;
	else if (next_tile == 'C')
		st->coin--;
	else if (next_tile == 'E')
	{
		ft_printf("Count: %d\n", st->steps + 1);
		close_window(st);
	}
	update_position(st, new_x, new_y);
}

int	main(int argc, char *argv[])
{
	t_m	st;

	if (argc != 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	check_argv(argv[1]);
	fill_st(argv[1], &st);
	check_map(&st);
	st.map[st.exit_x][st.exit_y] = '0';
	st.mlx = mlx_init();
	st.win = mlx_new_window(st.mlx, st.length * 64, st.hight * 64, "so_long");
	load_images(&st);
	draw_map(&st);
	mlx_key_hook(st.win, handle_key, &st);
	mlx_hook(st.win, 17, 0L, close_window, &st);
	mlx_loop(st.mlx);
}
