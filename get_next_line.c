/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:30:28 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/22 12:41:52 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define BUFFER_SIZE 1

char	*read_line(int fd);

char	*get_next_line(int fd)
{
	static char	*str;

	if (fd < 0)
		return (NULL);
	str = read_line(fd);
	return (str);
}

char	*read_line(int fd)
{
	char	*buf;
	char	*nl_string;
	int		read_val;

	read_val = 1;
	nl_string = NULL;
	buf = ft_calloc(sizeof(char) * (BUFFER_SIZE + 1), 1); // Fix conditional move depends on uninitialised value
	while (!has_newline(buf) && read_val != 0)
	{
		if (read_val < 0)
			return (NULL);
		read_val = read(fd, buf, BUFFER_SIZE);
		nl_string = ft_strjoin(nl_string, buf);
	}
	free(buf);
	return (nl_string);
}

int		main(void)
{
	int		fd;
	char	*str;

	fd = open("testing", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	close(fd);
}
