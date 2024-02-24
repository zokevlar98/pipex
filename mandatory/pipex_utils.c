/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:06:20 by zqouri            #+#    #+#             */
/*   Updated: 2024/02/18 18:06:20 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path_env(char *cmd, char *envp[])
{
	char	**path_s;
	char	*path;
	int		i;
	char	*tmp;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	path_s = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path_s[i])
	{
		tmp = ft_strjoin(path_s[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);// imkan 5assa free l arr 2 dimontion
		free(path);
		i++;
	}
	return (ft_free(path_s), NULL);
}

void	execute(char *cmd, char *envp[])
{
	char	**command;
	char	*path;

	command = ft_split(cmd, ' ');
	path = find_path_env(command[0] , envp);
	if (!path)
	{
		ft_free(command);
		error();
	}
	if (execve(path, command, envp) == -1)
		error();
}