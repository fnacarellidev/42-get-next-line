/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:30:28 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/16 00:10:11 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_fdstruct	*fd_node;
	t_fdstruct			*node_matching_fd;
	char *c = "oi";

	if (!fd_node)
		fd_node = ft_newnode(fd);
	else if (fd_node->fd == fd)
		return (fd_node->line);
	else if (has_matching_fd(fd_node, fd))
	{
		while (fd_node->fd != fd)
			fd_node = fd_node->next;
		printf("%d\n", fd_node->fd);
		return (fd_node->line);
	}
	else
		ft_nodeadd_back(&fd_node, ft_newnode(fd));
	return (c);
}

int main()
{
	int fd;
	int	fd2;
	char *c;

	fd = open("testing.txt", O_RDONLY);
	fd2 = open("testing2.txt", O_RDONLY);
	printf("%d\n", fd);
	c = get_next_line(fd);
	printf("%d\n", fd2);
	c = get_next_line(fd2);
	c = get_next_line(fd2);
	close(fd);
	close(fd2);
}
