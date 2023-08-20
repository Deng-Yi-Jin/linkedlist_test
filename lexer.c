#include "minishell.h"

void	parse_input(char *input, char **envp)
{
	t_token	*tokens;
	int		i;

	i = 0;
	tokens->value = (char **)malloc(sizeof(char *) * ft_strlen(input) + 1);
	tokens->value[i] = ft_strtok(input, " ");
	i++;
	while (tokens->value[i++])
	{
		tokens->type = check_type(tokens->value[i], tokens);
		tokens->next = tokens;
		tokens->prev = token_join(tokens, tokens->value[i]);
		tokens->value[i] = ft_strtok(NULL, " ");
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_token	*tokens;

	input = readline("minishell$ ");
	parse_input(input, envp);
	return (0);
}