/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:22:56 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/22 12:47:45 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>

char		*get_next_line(int fd);
void		ft_strcpy(char *dest, const char *src);
void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_strlen(char *str);
int			has_newline(char *str);
char		*ft_strjoin(char *str, char *buf);

#endif
