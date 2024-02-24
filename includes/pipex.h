/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 00:57:05 by zqouri            #+#    #+#             */
/*   Updated: 2024/02/24 14:42:10 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>
# include <sys/wait.h>

//void	process_parent(int *fd, char *argv[], char *envp[]);
void	process_child(int *fd, char *argv[], char *envp[]);
void	process_child_2(int *fd, char *argv[], char *envp[]);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(char *str);
void	error(void);
char	*find_path_env(char *cmd, char *envp[]);
void	execute(char *cmd, char *envp[]);
char	**ft_split(char *s, char c);
void	ft_free(char **tab);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif