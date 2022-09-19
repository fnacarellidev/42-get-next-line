/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:22:56 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/16 19:29:32 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include <stdlib.h>

typedef struct			s_fdstruct
{
	int					fd;
	int					index_to_search;
	char				*line;
	struct s_fdstruct	*next;
}						t_fdstruct;

char		*get_next_line(int fd);
int			has_matching_fd(t_fdstruct *node, int fd);
void		ft_nodeadd_back(t_fdstruct **head, t_fdstruct *new);
t_fdstruct	*ft_newnode(int fd);
t_fdstruct	*ft_nodelast(t_fdstruct *node);

#endif
