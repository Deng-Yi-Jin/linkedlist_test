# include "minishell.h"

// done, any question?
char *ft_strtok(char *str, const char *delim)
{
    static char *s;
    int i;
    int j;

    if (str != NULL)
        s = str;
    i = 0;
    while (s[i])
    {
        j = 0;
        while (delim[j])
        {
            if (s[i] == delim[j])
            {
                s[i] = '\0';
                s = &s[i + 1];
                return (s);
            }
            j++;
        }
        i++;
    }
    return (NULL);
}

// int	main(void)
// {
// 	char str[] = "hello world";
// 	char delim[] = " ";
// 	char *token;

// 	token = malloc(sizeof(char) * ft_strlen(str) + 1);
// 	token = ft_strtok(str, delim);
// 	while (token != NULL)
// 	{
// 		printf("%s\n", token);
// 		token = ft_strtok(NULL, delim);
// 	}
// 	return (0);
// }
