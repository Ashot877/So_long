/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:52:36 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/06/02 17:52:38 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_coin(t_m *st)
{
	int	c;
	int	i;
	int	j;

	c = 0;
	i = 0;
	while (st->map[i])
	{
		j = 0;
		while (st->map[i][j])
		{
			if (st->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (c > 0)
		st->coin = c;
	else
		error_(st);
}

void	check_player(t_m *st)
{
	int	p;
	int	i;
	int	j;

	p = 0;
	i = 0;
	while (st->map[i])
	{
		j = 0;
		while (st->map[i][j])
		{
			if (st->map[i][j] == 'P')
			{
				st->player_x = j;
				st->player_y = i;
				p++;
			}
			j++;
		}
		i++;
	}
	if (p != 1)
		error_(st);
}

void	check_exit(t_m *st)
{
	int	e;
	int	i;
	int	j;

	e = 0;
	i = 0;
	while (st->map[i])
	{
		j = 0;
		while (st->map[i][j])
		{
			if (st->map[i][j] == 'E')
			{
				st->exit_x = i;
				st->exit_y = j;
				e++;
			}
			j++;
		}
		i++;
	}
	if (e != 1)
		error_(st);
}

void	check_wall(t_m *st)
{
	int	i;
	int	j;

	i = 0;
	while (st->map[i])
	{
		j = 0;
		while (st->map[i][j])
		{
			if ((i == 0 || i == ((st->hight) - 1)) && (st->map)[i][j] != '1')
				error_(st);
			else if ((j == 0 || j == ((st->length) - 1))
				&& (st->map)[i][j] != '1')
				error_(st);
			else if (st->map[i][j] != 'P' && st->map[i][j] != 'E'
				&& st->map[i][j] != 'C' && st->map[i][j] != '0'
				&& st->map[i][j] != '1')
				error_(st);
			j++;
		}
		i++;
	}
}

void	check_map(t_m *st)
{
	check_coin(st);
	check_player(st);
	check_exit(st);
	check_wall(st);
	check_paths(st);
}
