/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 00:57:03 by zqouri            #+#    #+#             */
/*   Updated: 2024/02/27 21:07:53 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	process_child(int *fd, char *argv[], char *envp[])
{
	int	input_file;

	input_file = open(argv[1], O_RDONLY, 0666);
	if (input_file == -1)
		error();
	if (dup2(input_file, STDIN_FILENO) == -1)
		error();
	//close (input_file);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		error();
	close(fd[0]);
	//close(fd[1]);
	execute(argv[2], envp);
}

void	process_child_2(int *fd, char *argv[], char *envp[])
{
	int	output_file;

	output_file = open(argv[4], O_WRONLY, 0666);
	if (output_file == -1)
		error();
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error();
	if (dup2(output_file, STDOUT_FILENO) == -1)
		error();
	close(fd[1]);
	//close (fd[0]);
	//close(output_file);
	execute(argv[3], envp);
}

//void ff()
//{
//	system("leaks pipex");
//}

//int	main(int argc, char *argv[], char *envp[])
//{
//	int		fd[2];
//	pid_t	pid;
	
//	atexit(ff);
//	if (argc == 5)
//	{
//		if (pipe(fd) == -1)
//			error();
//		pid = fork();
//		if (pid == -1)
//			error();
//		if (pid == 0)
//			process_child(fd, argv, envp);
//		waitpid(pid, NULL, 0);
//		pid = fork();
//		if(pid == 0)
//			process_child_2(fd, argv, envp);
//		//waitpid(pid, NULL, 0);
//	}
//	else
//	{
//		ft_putstr_fd("\033[31mError: Bad arguments\n", 2);
//		ft_putstr_fd("Like : ./pipex file1 cmd1 cmd2 file2\n", 1);
//		exit (EXIT_FAILURE);
//	}
//	return (0);
//}
