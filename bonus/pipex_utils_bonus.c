/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:09:36 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/09 16:58:01 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_exeption(void)
{
	ft_putstr_fd("\033[31mError: Bad arguments\n", 2);
	ft_putstr_fd("Like : ./pipex file1 cmd1 cmd2 cmd3 ... file2\n", 1);
	ft_putstr_fd("     : ./pipex here_doc LIMITER cmd1 cmd2 ... file\n", 1);
	exit (EXIT_FAILURE);
}

int	ft_open(char *argv, int index)
{
	int	file;

	file = 0;
	if (index == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0666);
	else if (index == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (index == 2)
		file = open(argv, O_RDONLY, 0666);
	if (file == -1)
		error();
	return (file);
}

void	child_process(char *argv, char *envp[])
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}
