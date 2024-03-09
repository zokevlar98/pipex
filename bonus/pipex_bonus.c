/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:09:33 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/09 20:28:38 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	condition(char *LIMITER, int *fd)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", 1);
		line = get_next_line(STDIN_FILENO);
		if (!line || ((ft_strlen(LIMITER) == ft_strlen(line) - 1)
				&& !ft_strncmp(line, LIMITER, ft_strlen(LIMITER))))
		{
			if (line)
				free (line);
			break ;
		}
		write(*fd, line, ft_strlen(line));
		free(line);
	}
}

void	here_doc(int argc, char *LIMITER)
{
	int		fd[2];

	if (argc >= 6)
	{
		if (pipe(fd) == -1)
			error();
		condition(LIMITER, &fd[1]);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	else
		ft_exeption();
}

void	last_routine(char *cmd, int filename, char **envp)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		dup2(filename, STDOUT_FILENO);
		close(filename);
		execute(cmd, envp);
	}
}

void	herepipe(int argc, char **argv, char **envp)
{
	int	i;
	int	input_file;
	int	output_file;

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
		close(input_file);
	}
	while (i < argc - 2)
		child_process(argv[i++], envp);
	last_routine(argv[argc - 2], output_file, envp);
	close(output_file);
	close(0);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc >= 5)
		herepipe(argc, argv, envp);
	else
		ft_exeption();
	while (wait(NULL) != -1)
		continue ;
	return (0);
}
