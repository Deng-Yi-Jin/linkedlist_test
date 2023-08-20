#include "minishell.h"

t_token	*token_join(t_token *tokens, char *str)
{
	t_token	*new_token;

	new_token = create_token(0);
	if (!new_token || !tokens)
		return (NULL);
	tokens -> next = new_token;
	new_token -> prev = tokens;
	return (new_token);
}

t_token *first_last_token(t_token *tokens, bool is_last)
{
	if (!tokens)
		return (NULL);
	if (is_last)
	{
		while (tokens->next)
			tokens = tokens->next;
		return (tokens);
	}
	else
	{
		while (tokens->prev)
			tokens = tokens->prev;
		return (tokens);
	}
}

t_token *create_token(int type)
{
	t_token *tokens;

	tokens = malloc(sizeof(t_token));
	if (tokens == NULL)
		return (NULL);
	tokens->type = type;
	tokens->next = NULL;
	tokens->prev = NULL;
}

void	free_token(t_token *token)
{
	if (token->value)
		free(token->value);
	if (token->cmd_path)
		free(token->cmd_path);
	free(token);
}

