/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:43:14 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/22 12:44:39 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dest, const char *src)
{
	int		i;
	size_t	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (*(src + i))
	{
		*(dest + dest_len + i) = *(src + i);
		i++;
	}
}

char	*ft_strjoin(char *str, char *buf)
{
	char	*finalstr;
	int		received_null_str;

	received_null_str = 0;
	if (!str)
	{
		str = malloc(1 * sizeof(char));
		str[0] = '\0';
		received_null_str = 1;
	}
	if (!str || !buf)
		return (NULL);
	finalstr = ft_calloc(1, ft_strlen(str) + ft_strlen(buf) + 1);
	if (!finalstr)
		return (NULL);
	ft_strcpy(finalstr, str);
	ft_strcpy(finalstr, buf);
	*(finalstr + ft_strlen(str) + ft_strlen(buf)) = '\0';
	free(str);
	return (finalstr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (!nmemb || !size || (nmemb * size) / size != nmemb)
		return (NULL);
	ptr = (void *) malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < size * nmemb)
	{
		*((char *) ptr + i) = '\0';
		i++;
	}
	return (ptr);
}

int	has_newline(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}
