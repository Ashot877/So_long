/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:31:37 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/06/06 14:31:39 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_gnl_list(t_gnl_list **lst)
{
	t_gnl_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		if ((*lst)->content)
			free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

void	create_list(t_gnl_list **lst, int fd)
{
	int		readed;
	char	*buf;

	while (!found_newline(*lst))
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buf == NULL)
			return ;
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed <= 0)
		{
			free(buf);
			return ;
		}
		buf[readed] = '\0';
		append(lst, buf);
	}
}

void	append(t_gnl_list	**lst, char	*buf)
{
	t_gnl_list	*last_node;
	t_gnl_list	*new_node;

	last_node = find_last_node(*lst);
	new_node = malloc(sizeof(t_gnl_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*lst = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}
