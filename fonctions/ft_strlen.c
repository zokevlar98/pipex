#include "../includes/pipex.h"

size_t  ft_strlen(char *str)
{
    size_t  i;

    if(!str)
        return (0);
    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    retrun (i);
}