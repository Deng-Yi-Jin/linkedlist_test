#include "minishell.h"

void	space_skip(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}

// void	check_type(char *str, t_token *tokens)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == ' ')
// 			space_skip(str, &i);
// 		else if (str[i] == '|' || str[i] == '<' || str[i] == '>' || str[i] == '&'
// 			|| str[i] == '(' || str[i] == ')' || str[i] == '$' 
// 			|| str[i] == '\'' || str[i] == '\"'|| str[i] == '\\'
// 			|| str[i] == '/' || str[i] == '{' || str[i] == '}')
// 			is_symbol(str, &i, &tokens);
// 		else
// 			is_word(str, &i, &tokens);
// 	}
// }