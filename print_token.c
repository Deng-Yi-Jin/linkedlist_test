#include "minishell.h"

void	print_token(t_token *tokens, bool to_first, char *str)
{
	t_token *tmp;

	if (to_first == true)
		tmp = first_last_token(&tokens, false);
	else
		tmp = tokens;
	printf("----Printing Stack %s (Top to Down)-------\n", str);
	while (tmp)
	{
		printf("cmd: %s\n", tmp->cmd);
		printf("type: %d\n", tmp->type);
		tmp = tmp->next;
	}
}