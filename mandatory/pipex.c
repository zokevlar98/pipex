/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 00:57:03 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/09 20:28:59 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	process_child(int *fd, char *argv[], char *envp[])
{
	int	input_file;

	close(fd[0]);
	input_file = open(argv[1], O_RDONLY, 0666);
	if (input_file == -1)
		error();
	if (dup2(input_file, STDIN_FILENO) == -1)
		error();
	close (input_file);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		error();
	close(fd[1]);
	execute(argv[2], envp);
}

void	process_child_2(int *fd, char *argv[], char *envp[])
{
	int	output_file;

	close(fd[1]);
	output_file = open(argv[4], O_WRONLY | O_CREAT, 0666);
	if (output_file == -1)
		error();
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error();
	close (fd[0]);
	if (dup2(output_file, STDOUT_FILENO) == -1)
		error();
	close(output_file);
	execute(argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			process_child(fd, argv, envp);
		pid2 = fork();
		if (pid2 == 0)
			process_child_2(fd, argv, envp);
	}
	else
		usage();
	close(fd[1]);
	close(fd[0]);
	wait(NULL);
	wait(NULL);
	return (0);
}
