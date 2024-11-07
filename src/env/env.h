#ifndef ENV_H
# define ENV_H

# include "minishell.h"

int	copy_envp(t_env **environ, char **envp, t_list **list);

#endif // ENV_H