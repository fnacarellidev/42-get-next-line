/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:22:56 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/23 23:53:23 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
void	ft_strcpy(char *dest, const char *src);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *str, char *buf);
char	*ft_strchr(char *s, int c);
char	*fd_analysis(int fd, char *static_str);
char	*get_line(char *str);
char	*update_main_string(char *outdated_string);
char	*get_next_line(int fd);

#endif
