# Minishell
SCREEEN <br/>
Minishell is a reproduction of some basic functionalities of the Unix (bash) shell.<br/>
The shell allows users to interact with the operating system by executing<br/>
commands, managing processes, and working with files and directories.<br/>
Minishell is a significant project in the journey of 42 as it provides a valuable opportunity<br/>
to gain a comprehensive understanding of fundamental concepts<br/>
in operating systems and acquire essential skills in managing processes and system resources.

### Rules

    Minishell should:
  
    • Display a prompt when waiting for a new command.
    • Have a working history.
    • Not interpret unclosed quotes or special characters which are not required by the
      subject such as \ (backslash) or ; (semicolon).
    • Handle ’ (single quote) which should prevent the shell from interpreting the meta-
      characters in the quoted sequence.
    • Handle " (double quote) which should prevent the shell from interpreting the meta-
      characters in the quoted sequence except for $ (dollar sign).
    • Implement redirections:
      ◦ < should redirect input.
      ◦ > should redirect output.
      ◦ << should be given a delimiter, then read the input until a line containing the
        delimiter is seen. However, it doesn’t have to update the history!
      ◦ >> should redirect output in append mode.
    • Implement pipes (| character). The output of each command in the pipeline is
      connected to the input of the next command via a pipe.
    • Handle environment variables ($ followed by a sequence of characters) which
      should expand to their values.
    • Handle $? which should expand to the exit status of the most recently executed
    foreground pipeline.
    • Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
    • In interactive mode:
      ◦ ctrl-C displays a new prompt on a new line.
      ◦ ctrl-D exits the shell.
      ◦ ctrl-\ does nothing.
    • Your shell must implement the following builtins:
      ◦ echo with option -n
      ◦ cd with only a relative or absolute path
      ◦ pwd with no options
      ◦ export with no options
      ◦ unset with no options
      ◦ env with no options or arguments
      ◦ exit with no options
The ``readline`` function was used to read the string containing the shell commands; this is included in the readline library.</br>
The minishell prompt looks like this:

```
$USER@minishell $PWD $
```

### Installing and running the project:
  
  As mentioned previously, we use ``readline`` to read the string containing the shell commands. To make it more interactive, ``readline`` receives a string to be used as a prompt. We have heavily tweaked the looks of it to be nice to use. The prompt is structured as follows:

```
$USER@minishell $PWD $
```
  
  The program's otput will be formatted like this:
  
    ◦ timestamp_in_ms id has taken a fork
    ◦ timestamp_in_ms id is eating
    ◦ timestamp_in_ms id is sleeping
    ◦ timestamp_in_ms id is thinking
    ◦ timestamp_in_ms id died

  An example of program execution:

      SCREEBEEEEEN!

## Installing and running the project:

1- Clone the repo:
  
  ```sh
  git clone https://github.com/startaglia/philosopher.git philosopher
  ```

2- Enter in philosopher dir and compile the program with the `make` command
	
 ```
  cd philosopher
	make
 ```
4- Run the program then insert the parameters.

	./philo 5 200 400 200 4
 
### Makefile Available Targets:

`make` or `make all` - Makes exe file/s
`make clean` - Deletes all the resulting object files  
`make fclean` - Deletes the executables and all the resulting object files  
`make re` - fclean + all
</br></br>

## Techonologies

   <img src="https://github.com/devicons/devicon/blob/master/icons/linux/linux-original.svg" title="Linux" alt="Linux Logo" width="40" height="40" align="left" /> 
   <img src="https://github.com/devicons/devicon/blob/master/icons/c/c-original.svg" title="C" alt="C Logo" width="40" height="40" align="left" /> </br></br>

## Sources
  [The Dining Philosopher’s Problem](https://medium.com/swlh/the-dining-philosophers-problem-bbdb92e6b788).</br>
  [Dining philosophers problem-wiki](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
   
## Authors

### Simone Tartaglia -  startaglia89@gmail.com - <a href="https://github.com/startaglia" target="_blank"><img align="center" src="https://icon-library.com/images/github-icon-svg/github-icon-svg-0.jpg" height="30" width="30" /></a> <a href="https://www.linkedin.com/in/simone-tartaglia-134723248/" target="_blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="https://www.linkedin.com/in/simone-tartaglia-134723248/" height="30" width="30" /></a>
