#ifndef COMMANDS_H
# define COMMANDS_H

# include "minishell.h"
# include "config.h"
// Include any necessary headers here

// Declare your function prototypes here

/* ************************************************************************** */
/*                                 COMMANDS                                   */
/* ************************************************************************** */

t_command	*create_command(char *cmd, char *arg);
void		execute_command(t_command *cmd);
void		redirect_output(int fd);
void		redirect_input(int fd);
void		create_child(t_command *cmd, int *pipefd, int child_num);
void		pipe_commands(t_command *cmd1, t_command *cmd2);
void		handle_parent(int *pipefd, pid_t pid1, pid_t pid2);
char		*get_cmd_path(char *cmd, char **envp);
t_command	*parse_command(char *input, char **environ);
void		free_command(t_command **cmd);

/* // Builtin functions
int			execute_builtin(t_command *cmd);
int			execute_external(t_command *cmd);
int			execute_pipe(t_command *cmd);
int			execute_redirection(t_command *cmd);
int			execute_semicolon(t_command *cmd);
int	execute_tree(t_command *cmd); */

#endif // COMMANDS_H