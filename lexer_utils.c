#include "minishell.h"

void	space_skip(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}

void	check_type(char *input, t_token *tokens)
{
	int	i;

	i = 0;
	while (input[i])
	{
		tokens = create_token(0);
		if (ft_isalpha(input[i]) == true || ft_isdigit(input[i]) == true)
			is_word(input, &i, &tokens);
		else if (input[i] == ' ')
			space_skip(input, &i);
		else if (input[i] == '|' || input[i] == '<' || input[i] == '>' || input[i] == '&'
			|| input[i] == '(' || input[i] == ')' || input[i] == '$' 
			|| input[i] == '\'' || input[i] == '\"' || input[i] == '{' || input[i] == '}')
			is_symbol(input, &i, &tokens);
		else
		{
			printf("Error: Invalid character\n");
			i++;
		}
		check_error(tokens);
	}
}