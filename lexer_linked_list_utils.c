#include "minishell.h"

t_token *create_token(char *cmd, int type)
{
	t_token	*newnode;

	newnode = malloc(sizeof(t_token));
	if (newnode == NULL)
		return (NULL);
	newnode -> cmd = cmd;
	newnode -> type = type;
	newnode -> next = NULL;
	newnode -> prev = NULL;
	return (newnode);
}

// creates a new token
t_token	*add_tokens(t_token *tokens, char *input, int type)
{
	t_token	*new;

	new = create_token(input, type);
	if (!new)
		return (NULL);
	if (!(tokens))
		return (new);
	// tokens = malloc(sizeof(t_token));
	tokens -> next = new;
	new -> prev = tokens;
	return (new);
}

t_token	*lst_first_last(t_token *tokens, bool is_last)
{
	if (is_last == true)
	{
		while (tokens -> next != NULL && tokens != NULL)
			tokens = tokens -> next;
		return (tokens);
	}
	while (tokens -> prev != NULL && tokens != NULL)
		tokens = tokens -> prev;
	return (tokens);
}

void	free_stack(t_token **tokens, void (*del)(void *))
{
	t_token	*tmp;

	if (!tokens)
		return ;
	while (*tokens)
	{
		tmp = (*tokens) -> next;
		del((*tokens) -> cmd);
		free(*tokens);
		*tokens = tmp;
	}
}

void	print_stack(t_token *tokens)
{
	tokens = lst_first_last(tokens, false);
	while (tokens)
	{
		if (tokens != NULL)
		{
			printf("stack_a: %s\n", tokens->cmd);
			printf("stack_a type: %d\n", tokens->type);
			printf("stack_a address: %p\n", tokens);
			tokens = tokens->next;
		}
	}
}

