
#ifndef MINISHELL_H
# define MINISHELL_H

# include "Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>	
# include <unistd.h>
# include "lexer.h"
# include <dirent.h>
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>
# include <stdbool.h>

// Structure to hold tokens
typedef struct s_token
{
	int				type;
	char			**value;
	char			*cmd_path;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

char		*ft_strtok(char *str, const char *delim);

// Token functions
t_token		*first_last_token(t_token *tokens, bool is_last);
t_token		*token_join(t_token *tokens, char *str);
t_token 	*create_token(int type);
void		free_token(t_token *token);
int			check_type(char *str, t_token *tokens);
void		is_symbol(char *str, int *i, t_token **tokens);
void		is_word(char *str, int *i, t_token **tokens);
void		space_skip(char *str, int *i);
#endif