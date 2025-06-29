/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:47:35 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/03/18 17:47:43 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	dealloc(t_gnl_list **lst, t_gnl_list *clean_node, char *buf)
{
	t_gnl_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
	if (clean_node->content[0])
		*lst = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}

void	copy_str(t_gnl_list *lst, char *str)
{
	int	k;
	int	i;

	if (lst == NULL)
		return ;
	k = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k] = lst->content[i];
			k++;
			i++;
		}
		lst = lst->next;
	}
	str[k] = '\0';
}

int	len_to_newline(t_gnl_list *lst)
{
	int	i;
	int	len;

	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		lst = lst->next;
	}
	return (len);
}

int	found_newline(t_gnl_list *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->content[i] && i < BUFFER_SIZE)
		{
			if (lst->content[i] == '\n')
				return (1);
			i++;
		}
		lst = lst -> next;
	}
	return (0);
}

t_gnl_list	*find_last_node(t_gnl_list	*lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
