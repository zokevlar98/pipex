/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 00:57:05 by zqouri            #+#    #+#             */
/*   Updated: 2024/02/19 21:46:45 by zqouri           ###   ########.fr       */
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

void	process_parent(int *fd, char *argv[], char *envp[]);
void	process_child(int *fd, char *argv[], char *envp[]);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(char *str);
void	error(void);
#endif