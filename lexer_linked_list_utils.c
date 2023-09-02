#include "minishell.h"

t_token *create_token(char *cmd, int type)
{
	t_token	*newnode;

	newnode = malloc(sizeof(t_token));
	if (!newnode)
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
	tokens = malloc(sizeof(t_token));
	tokens -> next = new;
	new -> prev = tokens;
	return (new);
}

void	ft_lstclear_token(t_token **lst, void (*del)(void *))
{
	t_token	*newnode;
	t_token	*prevnode;

	if (!lst || !del)
		return ;
	prevnode = NULL;
	newnode = *lst;
	while (newnode->next != NULL)
	{
		prevnode = newnode;
		newnode = newnode->next;
		del(prevnode -> cmd);
		free(prevnode);
	}
	*lst = newnode;
}

