/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 00:57:03 by zqouri            #+#    #+#             */
/*   Updated: 2024/02/19 22:51:51 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	process_parent(int *fd, char *argv[], char *envp[])
{
	
}

void	process_child(int *fd, char *argv[], char *envp[])
{
	int	input_file;

	input_file = open(argv[1], O_RDONLY, 0666);
	if (input_file == -1)
		error();
	if (dup2(input_file, STDIN_FILENO) == -1)
		error();
	close (input_file);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		error();
	close(fd[0]);
	close(fd[1]);
	//execution
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid;
	(void)argv;
	(void)envp;
	
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			process_child(fd, argv, envp);
		pid = fork();
		if(pid == 0)
			process_child2();
		wait(NULL);
		wait(NULL);
		
	}
	else
	{
		ft_putstr_fd("\033[31mError:Bad arguments\n", 2);
		ft_putstr_fd("Like : ./pipex file1 cmd1 cmd2 file2\n", 1);
		exit (EXIT_FAILURE);
	}
	
	return (0);
}
