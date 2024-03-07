/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:09:33 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/08 00:24:57 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


void	here_doc(int argc, char *LIMITER)
{
	int		fd[2];
	char	*line;
	
	if (argc >= 6)
	{
		if (pipe(fd) == -1)
			error();
		//close(fd[0]);
		while (1)
		{
			ft_putstr_fd("Heredoc> ", 1);
			line = get_next_line(STDIN_FILENO);
			if(!line || !ft_strncmp(line, LIMITER, ft_strlen(LIMITER)))
			{
				if (line)
					free (line);
				break ;
			}
			write(fd[1], line, ft_strlen(line));
			write(fd[1], "\n", 1);
			free(line);
		}
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		//waitpid(pid, NULL, 0);
	}
	else
		ft_exeption();
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
		execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		//waitpid(pid, NULL, 0);
	}
}

void last_routine(char *cmd, int filename, char **envp)
{
	int pid;

	pid = fork();
	if (pid == -1)
		error();
	if(pid == 0)
	{
		dup2(filename, STDOUT_FILENO);
		execute(cmd, envp);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int	i;
	int	input_file;
	int	output_file;
	
	i = 2;
	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			here_doc(argc, argv[2]);
			output_file = ft_open(argv[argc - 1], 0);
		}
		else
		{
			i = 2;
			input_file = ft_open(argv[1], 2);
			output_file = ft_open(argv[argc - 1], 1);
			dup2(input_file, STDIN_FILENO);
			//close(input_file);
		}
		while (i < argc - 2)
			child_process(argv[i++], envp);
		last_routine(argv[argc - 2], output_file, envp);
	}
	else
		ft_exeption();
	return (0);
}
