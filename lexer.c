#include "minishell.h"

void	del(void *content)
{
	free(content);
}

void	parse_input(char *input, char **envp)
{
	t_token *tokens;

	check_type(input, tokens);
	// print_token(tokens, true, "tokens");
	// first_last_token(&tokens, false);
	// ft_lstclear_token(&tokens, del);
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