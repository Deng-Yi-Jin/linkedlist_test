#include "minishell.h"

void	space_skip(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}
