/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:21:28 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/13 09:16:36 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/history.h>
# include <readline/readline.h>

// Include any necessary headers here

# include "config.h"
# include "exe.h"
# include "libft.h"
# include "mt.h"
# include "parse.h"

typedef struct s_data
{
	pid_t			pid;
	t_mt			*list;
	t_env			*envp;
}					t_data;

typedef struct s_memory
{
	t_hash_table	*ht;
}					t_memory;

// Declare your function prototypes here

// clean_up.c
int					clean_up(t_hash_table *mem);

// shell.c
int					process_input(char *input, t_hash_table *ht);
int					shell_loop(t_hash_table *mem);

// init.c
t_hash_table		*init_memory(char **envp, int size);

// utils.c
int					ft_execute_list(t_mt *head, void *p, t_env *env,
						int (*proccess_node)(t_mt *, void *, t_env *));

void				insert_ptr(t_hash_table *mem, char *parent, char *aux,
						void *data, void (*free_func)(void **));
void				insert_description(t_hash_table *mem, char *key,
						char *data);
void				ft_set_priority(t_mt *list, void *param,
						void (*func)(t_mt *, void *));
int					pred(t_mt *lst, void *p);

# define PROMPT "minishell$ "

#endif