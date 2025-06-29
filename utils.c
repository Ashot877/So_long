/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:31:18 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/06/02 18:31:20 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map, int hight)
{
	char	**map_copy;
	int		i;

	map_copy = malloc((hight + 1) * sizeof(char *));
	i = 0;
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	init_map(t_m *st)
{
	int	i;

	st->map = malloc((st->hight + 1) * sizeof(char *));
	if (!st->map)
		exit(2);
	i = 0;
	while (i <= st->hight)
		st->map[i++] = NULL;
}

void	read_map_lines(t_m *st, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < st->hight)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			error_(st);
		}
		st->map[i] = str_clear(line, st);
		free(line);
		i++;
	}
	st->map[i] = NULL;
}

int	size_map_help(int fd, t_m *st, int size_x_prev)
{
	char	*line;
	int		size_y;
	int		size_x;

	size_y = 1;
	line = get_next_line(fd);
	while (line)
	{
		size_x = ft_strlen(line);
		if (size_x != size_x_prev)
		{
			close(fd);
			free(line);
			error_(st);
		}
		free(line);
		line = get_next_line(fd);
		size_y++;
	}
	return (size_y);
}

void	update_position(t_m *st, int new_x, int new_y)
{
	st->map[st->player_y][st->player_x] = '0';
	st->map[new_y][new_x] = 'P';
	st->player_x = new_x;
	st->player_y = new_y;
	st->steps++;
	if (st->coin == 0)
		st->map[st->exit_x][st->exit_y] = 'E';
	ft_printf("Count: %d\n", st->steps);
	draw_map(st);
}
