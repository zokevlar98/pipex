/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 00:57:05 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/09 21:03:20 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <stddef.h>
# include <sys/wait.h>
# include "../gnl/get_next_line.h"

void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(char *str);
void	error(void);
char	*find_path_env(char *cmd, char *envp[]);
void	execute(char *cmd, char *envp[]);
char	**ft_split(char *s, char c);
void	ft_free(char **tab);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_open(char *argv, int index);
void	ft_exeption(void);
char	*get_next_line(int fd);
char	**ft_split_up(char *s);
void	usage(void);
#endif