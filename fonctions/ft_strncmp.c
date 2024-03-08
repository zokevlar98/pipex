/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:03:21 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/08 09:33:42 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../includes/pipex_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (s1[i] == '\n' && s2[i] == '\0')
		return (0);
	while ((p1[i] == p2[i]) && (i < n - 1) && p1[i] && p2[i])
	{
		i++;
	}
	return (p1[i] - p2[i]);
}
