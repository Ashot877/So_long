/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:35:06 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/03/18 17:35:09 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl_list
{
	char				*content;
	struct s_gnl_list	*next;
}	t_gnl_list;
char				*get_next_line(int fd);
int					found_newline(t_gnl_list *list);
t_gnl_list			*find_last_node(t_gnl_list *list);
char				*get_line(t_gnl_list *list);
void				copy_str(t_gnl_list *list, char *str);
int					len_to_newline(t_gnl_list *list);
void				clear_lst(t_gnl_list **list);
void				dealloc(t_gnl_list **list,
						t_gnl_list *clean_node, char *buf);
void				create_list(t_gnl_list **list, int fd);
void				gnl_free_all(void);
void				create_list(t_gnl_list **lst, int fd);
void				free_gnl_list(t_gnl_list **lst);
void				append(t_gnl_list	**lst, char	*buf);
t_gnl_list			**get_static_lst(void);
void				append(t_gnl_list	**lst, char	*buf);
#endif