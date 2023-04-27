# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>
#include <termios.h>
#include <readline/readline.h>
#include <readline/history.h>

static int	get_n_word(const char *s, char c)
{
	int	i;
	int	count;
	int	trig;

	trig = 0;
	count = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && trig == 0)
		{
			count += 1;
			trig = 1;
		}
		else if (s[i] == c)
			trig = 0;
		i++;
	}
	return (count);
}

static char	**malloc_func(char const *s, char c)
{
	char	**res;

	res = NULL;
	if (!s)
		return (0);
	res = malloc(sizeof(char *) * (get_n_word(s, c) + 1));
	if (!res)
		return (0);
	return (res);
}

static char	*alloc_word_mem(const char *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (end - start + 1));
	while (start < end)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		start;
	int		end;

	j = 0;
	i = 0;
	res = malloc_func(s, c);
	while (s[j] != 0)
	{
		if (s[j] != c)
		{
			start = j;
			while (s[j] != c && s[j])
				j++;
			end = j;
			res[i++] = alloc_word_mem(s, start, end);
		}
		else if (s[j] == c)
			j++;
	}
	res[i] = 0;
	return (res);
}

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

// void	signal_ctlc(int sig)
// {char *s = "manniaddio\n";
// 	if (sig == SIGINT)
// 	{
// 		write(STDERR_FILENO, s, ft_strlen(s));
// 		rl_replace_line("Riprova", 5);
// 		rl_on_new_line();
// 		rl_redisplay();
// 	}
// }
int str_cmp(char *s1, char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}
void    execute(char **arg, char *env[])
{
    int pid = fork();
    if (pid < 0)
        return ;
    if (pid == 0)
    {
        if (!str_cmp("ls", arg[0]))
            execve("/bin/ls", arg, env);
        if (!str_cmp(">", arg[1]))
        {
            int read = open(arg[2], O_CREAT | O_WRONLY | O_TRUNC, 0777);
            // dup2(read, STDOUT_FILENO);
            // close(read);
            execve("/bin/echo", arg, env);
        }
        if (!str_cmp("echo", arg[0]))
            execve("/bin/echo", arg, env);
        if (!str_cmp("exit", arg[0]))
            exit(0);
    }
    close(read);
    waitpid(pid, NULL, 0);
}

int main(int ac, char *av[], char *env[]) {
    char *input;
    while (1)// char* input;
    {
        input = readline("> ");
        // signal(SIGINT, signal_ctlc);
        add_history(input);
    
        char **matrix = ft_split(input, ' ');
        execute(matrix, env);
    }
    free(input);

    // while (1) {
    //     input = readline("> ");  // visualizza il prompt "> " e legge l'input dell'utente
    //     if (!input) {  // l'utente ha premuto CTRL+D per terminare il programma
    //         printf("\n");
    //         break;
    //     }
    //     if (strcmp(input, "exit") == 0) {  // se l'utente ha digitato "exit", termina il programma
    //         printf("Bye!\n");
    //         free(input);
    //         break;
    //     }
    //     printf("Hai digitato: %s\n", input);
    //     add_history(input);  // aggiunge l'input alla cronologia di readline
    //     free(input);  // dealloca la memoria allocata da readline per l'input
    // }
    return 0;
}

