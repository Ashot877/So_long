/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:17:58 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/06/02 18:17:59 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, t_check *check)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		check->coin++;
	if (map[y][x] == 'E')
		check->exit_found = 1;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, check);
	flood_fill(map, x - 1, y, check);
	flood_fill(map, x, y + 1, check);
	flood_fill(map, x, y - 1, check);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	check_paths(t_m *st)
{
	char	**map_copy;
	t_check	check;

	map_copy = copy_map(st->map, st->hight);
	check.coin = 0;
	check.total_coin = st->coin;
	check.exit_found = 0;
	flood_fill(map_copy, st->player_x, st->player_y, &check);
	if (check.coin != check.total_coin || !check.exit_found)
	{
		free_map(map_copy);
		error_(st);
	}
	free_map(map_copy);
}
