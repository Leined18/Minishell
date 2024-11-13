#ifndef SHELL_H
# define SHELL_H

// Include any necessary headers here
# include "config.h"
# include "minishell.h"
# include <readline/history.h>
# include <readline/readline.h>

// Declare your function prototypes here
int			clean_up();
int			process_input(char *input, t_data *data);
int			shell_loop(t_memory *mem);

// init.c
int			init_memory(t_memory *mem, int ac, char **av, char **envp);


#endif // SHELL_H