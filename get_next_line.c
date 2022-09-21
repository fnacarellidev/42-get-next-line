/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:30:28 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/21 16:55:27 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define BUFFER_SIZE 42

char	*get_next_line(int fd)
{
	static char	*str;
}

int main()
{
	int fd;

	fd = open("testing.txt", O_RDONLY);

	close(fd);
	printf("%s\n", get_next_line(fd));
}
