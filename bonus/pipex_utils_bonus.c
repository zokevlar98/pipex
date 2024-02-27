/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:09:36 by zqouri            #+#    #+#             */
/*   Updated: 2024/02/26 15:40:12 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exeption(void)
{
	ft_putstr_fd("\033[31mError: Bad arguments\n", 2);
	ft_putstr_fd("Like : ./pipex file1 cmd1 cmd2 cmd3 ... file2\n", 1);
	ft_putstr_fd("     : ./pipex  here_doc LIMITER cmd1 cmd2 cmd3 ... file2\n", 1);
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