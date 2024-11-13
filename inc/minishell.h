/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:21:28 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/13 13:13:06 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "config.h"
# include "exe.h"
# include "libft.h"
# include "memtrack.h"
/* # include "parse.h"
# include "memtrack.h" */

typedef struct s_data
{
	t_env			*envp;
	pid_t			pid;
	t_list			*list;
}					t_data;

typedef struct s_tree
{
	t_data			*data;
	struct s_tree	*left;
	struct s_tree	*right;
	t_list			*list;
}					t_tree;

typedef struct s_node
{
	t_list			*list;
	t_tree			*tree;
	t_data			*data;
	t_command		*command;
	struct s_node	*next;
}					t_node;

typedef struct s_memory
{
	t_data *data; // Datos de la shell [command, pid]
	t_tree *tree; // Árbol de datos [cat, priority]-> [ls -l, priority]-> [grep,
	t_node *node; // Nodo de datos [cat]-> [ls -l]-> [grep]-> [>] -> [txt.txt]
	char			**av;
	int				ac;
}					t_memory;

# define PROMPT "minishell$ "

#endif