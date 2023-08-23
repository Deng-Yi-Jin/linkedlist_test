#include "minishell.h"

void	check_error(t_token *tokens)
{
	printf ("tokens->prev address: %p\n", tokens->prev);
	// printf ("tokens->prev->prev address: %p\n", tokens->prev->prev);
	// if (tokens->prev->type == PIPE && tokens->prev->prev->type != WORD)
	// {
	// 	printf("syntax error near unexpected token `|'\n");
	// 	exit(1);
	// }
	// else if (tokens->prev->prev->type == DOUBLE_AND && tokens->prev->type == ANDPARSEN)
	// {
	// 	printf("syntax error near unexpected token `&&'\n");
	// 	exit(1);
	// }
}
