#include "../includes/pipex.h"

int	error(char *str)
{
	write(2,str,ft_strlen(str));
	return (1);
}