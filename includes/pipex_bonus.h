/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:51:01 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/09 21:03:38 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>
# include <sys/wait.h>
# include "../gnl/get_next_line.h"

void	here_doc(int argc, char *LIMITER);
void	child_process(char *argv, char *envp[]);
void	last_routine(char *cmd, int filename, char **envp);
void	ft_exeption(void);
int		ft_open(char *argv, int index);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char *s, char c);
void	ft_free(char **tab);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	error(void);
void	execute(char *cmd, char *envp[]);
char	*find_path_env(char *cmd, char *envp[]);
char	**ft_split_up(char *s);
#endif