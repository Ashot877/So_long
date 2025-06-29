/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 19:46:57 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/05/31 19:46:58 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	size_map(t_m *st, char *argv)
{
	int		fd;
	int		size_y;
	int		size_x_prev;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_(st);
	size_y = 0;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		error_(st);
	}
	size_x_prev = ft_strlen(line);
	free(line);
	size_y = size_map_help(fd, st, size_x_prev);
	st->length = size_x_prev;
	st->hight = size_y;
	close(fd);
}

void	create_st(t_m *st)
{
	st->length = -1;
	st->hight = -1;
	st->map = NULL;
	st->coin = 0;
	st->player_x = -1;
	st->player_y = -1;
	st->steps = 0;
}

char	*str_clear(char *str, t_m *st)
{
	int		i;
	char	*s;

	if (!str)
		return (NULL);
	s = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!s)
		error_(st);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	fill_map(t_m *st, char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_(st);
	init_map(st);
	read_map_lines(st, fd);
	close(fd);
}

void	fill_st(char *argv, t_m *st)
{
	create_st(st);
	size_map(st, argv);
	fill_map(st, argv);
}
