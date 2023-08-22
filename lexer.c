#include "minishell.h"

void	del(void *content)
{
	free(content);
}

void	parse_input(char *input, char **envp)
{
	t_token *tokens;
	int		i;

	i = 0;
	while (input[i])
	{
		tokens = create_token(0);
		if (ft_isalpha(input[i]) == true)
			is_word(input, &i, tokens);
		else if (input[i] == ' ')
			space_skip(input, &i);
		else if (input[i] == '|' || input[i] == '<' || input[i] == '>' || input[i] == '&'
			|| input[i] == '(' || input[i] == ')' || input[i] == '$' 
			|| input[i] == '\'' || input[i] == '\"'|| input[i] == '\\'
			|| input[i] == '/' || input[i] == '{' || input[i] == '}')
			is_symbol(input, &i, tokens);
	}
	first_last_token(tokens, false);
	ft_lstclear_token(&tokens, del);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	while (1)
	{
		input = readline("minishell$ ");
		parse_input(input, envp);
		free(input);
	}
	return (0);
}