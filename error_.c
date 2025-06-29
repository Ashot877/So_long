/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:20:37 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/06/02 15:20:39 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_st(t_m *st)
{
	if (st)
	{
		if (st->map)
			free_st_map(st);
	}
}

void	error_(t_m *st)
{
	ft_printf("Error\n");
	free_st(st);
	gnl_free_all();
	exit(2);
}
