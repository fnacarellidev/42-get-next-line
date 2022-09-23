/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:30:28 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/23 20:27:47 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define BUFFER_SIZE 1

char	*fd_analysis(int fd, char *static_str);
char	*filter(char *str);
char	*fix_static_string(char *str);

char	*get_next_line(int fd)
{
	static char	*str;
	char		*new_line;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = fd_analysis(fd, str);
	if (!ft_strlen(str))
		return (NULL);
	else
	{
		new_line = filter(str);
		str = fix_static_string(str);
	}
	return (new_line);

}

char	*fd_analysis(int fd, char *static_str)
{
	char	*buf;
	int		read_val;
	
	read_val = 1;
	buf = malloc(BUFFER_SIZE + 1);
	while (!ft_strchr(static_str, '\n'))
	{
		read_val = read(fd, buf, BUFFER_SIZE);
		if (read_val <= 0)
		{
			free(buf);
			return (NULL);
		}
		buf[read_val] = '\0';
		static_str = ft_strjoin(static_str, buf);
		if (!static_str)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (static_str);
}

char	*fix_static_string(char *str)
{
	int		j;
	size_t	i;
	size_t	str_len;
	char	*fixed_string;

	if (str)
	{
		i = 0;
		j = 0;
		str_len = ft_strlen(str);
		while (str[i] != '\n' && str[i])
			i++;
		if (str[i] == '\n')
			i++;
		if (i == str_len)
		{
			free(str);
			return (NULL);
		}
		fixed_string = malloc(str_len - i + 1);
		while (str[i + j])
		{
			fixed_string[j] = str[i + j];
			j++;
		}
		fixed_string[j] = '\0';
		free(str);
		return (fixed_string);
	}
	return (NULL);
}

char	*filter(char *str)
{
	int		i;
	int		j;
	char	*filtered_string;

	i = 0;
	j = 0;
	if (str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (str[i] == '\n')
		{
			i++;
			filtered_string = malloc(i + 1);
			while (str[j] != '\n')
			{
				filtered_string[j] = str[j];
				j++;
			}
			filtered_string[j] = '\n';
			filtered_string[j + 1] = '\0';
			return (filtered_string);
		}
	}
	return (NULL);
}

int		main(void)
{
	int		fd;
	char	*str;

	fd = open("hardtesting.txt", O_RDONLY);
	for (int i = 0; i <= 10; i++)
	{
		str = get_next_line(fd);
		printf("%s\n", str);
		free(str);
	}
	close(fd);
}
