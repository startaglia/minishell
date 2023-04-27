# Notes
### **readline(char \*prompt)**
La funzione readline visualizza il prompt e legge l'input che l'utente inserisce, simile allo scanf. Prende come solo argomento, una stringa che sarebbe il prompt da mostrare all'utente.
### **add_history(const char \*string)**
La funzione add_history() aggiunge il suo unico argomento alla cronologia degli input letti da readline. Questa cronologia viene di volta in volta salvata in un file .bash_history che sta nella home_dir.
### **rl_clear_history()**
La funzione rl_clear_history() rimuove la cronologia salvata dalla funct add_history e libera la memoria. Non prende nessun parametro.
 ### **rl_on_new_line()**
La funzione rl_on_new_line() é una funzione che segnala a readline che il cursore é stato spostato su una nuova riga, si usa per rendere l'out piú leggibile. Non prende nessun parametro.
 ### **rl_replace_line(const char \*string, int undo)**
La funzione rl_replace_line() consente di sostituire una stringa con una nuova riga. prende due parametri, il primo é la stringa che andrá a sostituire quella di input corrente, il secondo parametro é un intero che puó essere 1 o 0; se 1 indica che si deve eliminare l' operazione di undo della riga precedente, se 0 no.
### **rl_redisplay()**
La funzione rl_redisplay() é usata per aggiornare la riga di input a seguito di qualche precedente modifica dell' utente.
### **access(const char \*path, int mode)**
La funzione access() si utilizza per controllare se un file dispone di permessi di accesso; restituisce 0 se é verificato, -1 se non é verificato. La funzione prende due argomenti, il primo é la path del file o dellla directory da verificare, il secondo é una maschera di bit che specifica i permessi di accesso richiesti; la maschera di bit ha i seguenti valori:
- R_OK: verifica se il file o la directory hanno il permesso di lettura.
- W_OK: verifica se il file o la directory hanno il permesso di scrittura.
- X_OK: verifica se il file o la directory hanno il permesso di esecuzione.
- F_OK: verifica solo se il file o la directory esiste.
### **fork()**
La funzione fork é una chiamata di sistema che crea un nuovo processo duplicando il processo chiamante(processo padre). La prima volta che si utilizza il processo chiamante é la funzione main. Il processo duplicato(processo figlio) é identico al processo padre solo ha un PID diverso. La funzione fork non prende alcun parametro e restituisce un int che rappresenta il risultato dell'operazione. Nel processo padre restituisce il PID del processo figlio, nel processo figlio restituisce 0. Per qualsiasi errore restituisce -1.
Nel progetto minishell ogni comando che viene inserito deve creare un processo.
### **wait(int \*status)**
La funzione wait() viene utilizzata per attendere la terminazione di un processo figlio, creato dalla funzione fork(). Sospende l'esecuzione del processo padre finché uno dei processi figli non termina; la funzione wait puó anche essere utilizzata per restituire lo stato di terminazione del processo figlio. Prende un puntatore ad un int come parametro dove mette lo stato di terminazione del primo processo figlio che arriva. Se 0 il processo é terminato correttamente.
### **waitpid(pid_t pid, int \*status, int options)**
La funzione waitpid() é una variante della funzione wait(). A differenza della funzione wait permette di specificare quale processo attendere. Accetta 3 parametri:
- Il primo (pid_t pid) puó assumere a sua volta 3 valori:
  - pid > 0 rappresenta il pid specifico del processo da attendere.
  - pid == 0 il processo padre attende la terminazione del primo processo figlio che finisce.
  - pid == -1 il processo padre attende la terminazione del primo processo figlio che finisce, anche se di un altro processo padre.
- Il secondo (int *status) é una variabile puntatore ad int dove andrá lo stato di terminazione del processo figlio arrivato; se 0 il processo é terminato correttamente. 
- Il terzo (int options) specifica le condizioni di attesa.

Il valore di ritorno della funzione waitpid() é il PID del processo terminato o -1 se si verifica un errore.
### **wait4(pid_t pid, int \*status, int options, struct rusage \*rusage)**
La funzione wait4 é molto simile alla funzione waitpid, l'unica differenza é che ha un quarto parametro che sarebbe un puntatore ad una struttura rusage(definita nella lib sys/resource.h), che restituisce i valori di consumo di risorse del processo figlio. Inoltre wait4 da la possibilitá di attendere la terminazione di un gruppo di processi figli specificati.
La funzione wait4 é molto simile alla funzione waitpid, l'unica differenza é che ha un quarto parametro che sarebbe un puntatore ad una struttura rusage(definita nella lib sys/resource.h), che restituisce i valori di consumo di risorse del processo figlio. Inoltre wait4 da la possibilitá di attendere la terminazione di un gruppo di processi figli specificati.
### **void (\*signal(int sig, void (\*handler)(int)))(int)**
La funzione signal si utilizza per impostare un gestore di segnale. Prende due parametri, il primo é il segnale da gestire, il secondo é il puntatore alla funzione gestore del segnale.












# STEPS
- Studiare le funzioni base.
- Studiare i comandi bash da subject.
- Approfondire teoria var di ambiente.
- Ambiente di lavoro funzionante.
- Header file (strutture e lib).
- Funzione free_mem.

# TO DO
- METTERE I TIPI DI RITORNO A TUTTE LE DEFINIZIONI SCRITTE