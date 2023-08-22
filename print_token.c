#include "minishell.h"

void	print_token(t_token *tokens)
{
	tokens = first_last_token(tokens, false);
	while (tokens)
	{
		printf("cmd: %s\n", tokens->cmd);
		printf("type: %d\n", tokens->type);
		tokens = tokens->next;
	}
}