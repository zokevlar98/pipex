/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:45:44 by zqouri            #+#    #+#             */
/*   Updated: 2024/03/08 09:17:09 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../includes/pipex_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}
