#include "minishell.h"

void	space_skip(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}

int	check_type(char *str, t_token *tokens)
{
	int	i;

	i = 0;
	tokens = token_join(tokens, str);
	if (str[i] == ' ')
		space_skip(str, &i);
	if (str[i] == '|' || str[i] == '<' || str[i] == '>' || str[i] == '&'
		|| str[i] == '(' || str[i] == ')' || str[i] == '$' 
		|| str[i] == '\'' || str[i] == '\"'|| str[i] == '\\'
		|| str[i] == '/' || str[i] == '{' || str[i] == '}')
		is_symbol(str, &i, &tokens);
	// if (str[i] == is_word(str, &i, &tokens))
	// 	is_word(str, &i, &tokens);
	return (tokens->type);
}