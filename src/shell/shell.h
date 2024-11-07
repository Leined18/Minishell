#ifndef SHELL_H
# define SHELL_H

// Include any necessary headers here
# include "config.h"
# include "minishell.h"
# include <readline/readline.h>
# include <readline/history.h>

// Declare your function prototypes here
int			clean_up(t_memory *mem);
int			process_input(char *input, char **envp, pid_t pid);
int			shell_loop(char **envp, pid_t pid);

// init.c
int			init_memory(t_memory *mem, int ac, char **av, char **envp);

// utils.c
t_memory	*memget(t_memory **mem, int b);

#endif // SHELL_H