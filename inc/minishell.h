/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:21:28 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/09 10:57:04 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/history.h>
# include <readline/readline.h>

// Include any necessary headers here

# include "config.h"
# include "libft.h"
# include "mt.h"
# include "parse.h"
# include "exe.h"

typedef struct s_data
{
	pid_t			pid;
	t_env			*envp;
}					t_data;

typedef struct s_memory
{
	t_hash_table	*ht;
}					t_memory;

// Declare your function prototypes here

// clean_up.c
int			clean_up(t_memory *mem);

//shell.c
int			process_input(char *input, t_data *data);
int			shell_loop(t_memory *mem);

// init.c
t_memory	*init_memory(char **envp);

// utils.c
void		insert_ptr(t_hash_table *mem, char *parent, char *child, void *data,
				void (*free_func)(void **));
void		insert_description(t_hash_table *mem, char *key, char *data);

# define PROMPT "minishell$ "

#endif