/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:31:08 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/03/18 17:31:10 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear_lst(t_gnl_list **lst)
{
	t_gnl_list	*last_node;
	t_gnl_list	*clean_node;
	int			i;
	int			k;
	char		*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_gnl_list));
	if (buf == NULL || clean_node == NULL)
		return ;
	last_node = find_last_node(*lst);
	i = 0;
	k = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] && last_node->content[++i])
	{
		buf[k] = last_node->content[i];
		k++;
	}
	buf[k] = '\0';
	clean_node->content = buf;
	clean_node->next = NULL;
	dealloc(lst, clean_node, buf);
}

char	*get_line(t_gnl_list	*lst)
{
	int		str_len;
	char	*new_line;

	if (lst == NULL)
		return (NULL);
	str_len = len_to_newline(lst);
	new_line = malloc((str_len + 1) * sizeof(char));
	if (new_line == NULL)
		return (NULL);
	copy_str(lst, new_line);
	return (new_line);
}

void	gnl_free_all(void)
{
	t_gnl_list	**lst;

	lst = get_static_lst();
	free_gnl_list(lst);
}

t_gnl_list	**get_static_lst(void)
{
	static t_gnl_list	*lst = NULL;

	return (&lst);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	**lst;
	char				*line;

	lst = get_static_lst();
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(lst, fd);
	if (*lst == NULL)
		return (NULL);
	line = get_line(*lst);
	clear_lst(lst);
	return (line);
}

// char	*get_next_line(int fd)
// {
// 	static t_gnl_list	*lst;
// 	char				*next_line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	create_list(&lst, fd);
// 	if (lst == NULL)
// 		return (NULL);
// 	next_line = get_line(lst);
// 	clear_lst(&lst);
// 	return (next_line);
// }

// int main(void)
// {
// 	int	fd;

// 	fd =  open("Test.txt",O_RDONLY);
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	return(0);

// }