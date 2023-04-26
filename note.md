### **readline()**
La funzione readline legge l'input che l'utente inserisce, simile allo scanf.

`input = readline("> ");  // visualizza il prompt "> " e legge l'input dell'utente`

### **add_history(var)**
La funzione add_history() aggiunge, in questo esempio, la variabile var alla cronologia degli input letti da readline. Questa cronologia viene di volta in volta salvata in un file .bash_history che sta nella home_dir.

`add_history(input);  // aggiunge l'input alla cronologia di readline`

### **rl_clear_history()**
La funzione rl_clear_history() rimuove la cronologia salvata dalla funct add_history e libera la memoria.

 `rl_clear_history();`

 ### **rl_on_new_line()**
La funzione rl_on_new_line() posiziona il cursore su una nuova riga, si usa per rendere l'out piu leggibile.

 `rl_on_new_line();`

 ### **rl_replace_line()**
La funzione rl_replace_line() consente di sostituire una stringa con una nuova riga. prende due parametri, il primo é la stringa che andrá a sostituire quella presa precedentemente da readline, il secondo é il numero di caratteri che replace_line andrá a sostituire.

 `rl_clear_history();`

### **rl_replace_line()**
La funzione rl_replace_line() consente di sostituire una stringa con una nuova riga. prende due parametri, il primo é la stringa che andrá a sostituire quella presa precedentemente da readline, il secondo é il numero di caratteri che replace_line andrá a sostituire.

 `rl_clear_history();`

*Definizione 2*
