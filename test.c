/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:20:40 by startagl          #+#    #+#             */
/*   Updated: 2023/04/27 15:00:56 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int main(int ac, char **av)
{

	(void) ac;
	(void) av;
    char *input;
	pid_t pid;
    // while (1)
    // {
// ?||--------------------------------------------------------------------------------||
// ?||                                     ACCESS                                     ||
// ?||--------------------------------------------------------------------------------||
		if (access("esempio.txt", W_OK) == 0)
			printf("Il file esempio.txt esiste.\n");
		else
			printf("Il file esempio.txt non esiste.\n");
// ?||-------------------------------------------------------------------------------------||
// ?||                                      FORK, WAIT                                     ||
// ?||-------------------------------------------------------------------------------------||
    int status;
    pid = fork();

    if (pid == 0) {  // processo figlio
        printf("Processo figlio in esecuzione...\n");
        sleep(5);
        exit(0);  // termina il processo figlio
    } else if (pid < 0) {  // errore nella creazione del processo figlio
        printf("Errore nella creazione del processo figlio.\n");
        exit(1);
    } else {  // processo padre
        printf("Processo padre in esecuzione...\n");
        wait(&status);  // attesa del processo figlio
        if (WIFEXITED(status)) // macro che controlla lo stato di terminazione di un processo figlio. É 0 se il processo figlio termina correttamente
        { 
            printf("Il processo figlio è terminato con codice di uscita %d.\n", WEXITSTATUS(status)); // Macro che ottiene il valore di uscita di un processo figlio
        } else {
            printf("Il processo figlio non è terminato normalmente.\n");
        }
    }
	// if (pid > 0)
	// {
        // codice del processo padre
    // }
	// input = readline("Prompt > ");
	// add_history(input);
		
    // }
    free(input);
}