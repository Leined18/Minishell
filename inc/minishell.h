/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:21:28 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/28 15:18:35 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <signal.h>



typedef struct s_data
{
	t_command		*command;
}					t_data;

typedef struct s_tree
{
	t_data			*data;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

typedef struct s_node
{
    t_tree			*tree;
    t_data			*data;
    struct s_node	*next;
}					t_node;

typedef struct s_memory
{
	t_data			*data;
	t_tree			*tree;
    t_node			*node;
	char			**envp;
	char			**av;
	int				ac;

}					t_memory;

# define PROMPT "minishell$ "

void				signal_setup(void);
void				send_signal(int pid, int signal);
void				signal_handler(int signum);

void				shell_loop(char **envp, pid_t pid);
void				process_input(char *input, char **envp);

#endif