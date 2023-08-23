
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
	char			*cmd;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

char		*ft_strtok(char *str, const char *delim);

// Token linked listfunctions
t_token		*first_last_token(t_token **tokens, bool is_last);
void		token_lstadd_back(t_token **lst, t_token *new);
t_token		*find_last_token(t_token *lst);
t_token 	*create_token(int type, t_token *tokens);
void		ft_lstclear_token(t_token **lst, void (*del)(void *));
void		del(void *content);

// Lexer utils
void		check_type(char *input);
void		is_symbol(char *str, int *i, t_token **tokens);
void		is_word(char *str, int *i, t_token **tokens);
void		space_skip(char *str, int *i);


// Parsing functions
void		check_error(t_token *tokens);

void		print_token(t_token *tokens, bool to_first, char *str);
#endif