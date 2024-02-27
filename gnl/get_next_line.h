/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:53:42 by zqouri            #+#    #+#             */
/*   Updated: 2024/02/26 19:08:02 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *src);
char	*ft_strjoin_get_next(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*get_line_m(char *line);
size_t	ft_strlen_get_next(const char *s);
char	*readed(int fd, char *line);
#endif
