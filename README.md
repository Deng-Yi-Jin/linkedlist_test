# linkedlist_test

test compile:
1. cd Libft
2. make
3. drag libft.a outside
4. gcc -o minishell lexer_check_seperator.c lexer.c lexer_linked_list_utils.c lexer_utils.c print_token.c lexer_symbol_error.c libft.a -lreadline -fsanitize=address -ggdb