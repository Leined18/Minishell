#ifndef ENV_H
# define ENV_H

# include "minishell.h"
# include "shell.h"

int	copy_envp(t_env **environ, char **envp, t_ref **ref);

#endif // ENV_H