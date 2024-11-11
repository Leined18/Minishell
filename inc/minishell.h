/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:21:28 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/11 13:15:35 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "config.h"
# include "libft.h"
# include "exe.h"


typedef struct s_data
{
	t_env			*envp;
	pid_t			pid;
	t_list			*list;
	t_ref			**ref;
}					t_data;

typedef struct s_tree
{
	t_data			*data;
	struct s_tree	*left;
	struct s_tree	*right;
	t_list			*list;
	t_ref			**ref;
}					t_tree;

typedef struct s_node
{
	t_ref			**ref;
	t_list			*list;
	t_tree			*tree;
	t_data			*data;
	t_command		*command;
	struct s_node	*next;
}					t_node;

typedef struct s_memory
{
	t_list *list; // Lista de punteros a liberar referencias [&]->[&]->[&]->[&]
	t_data *data; // Datos de la shell [command, pid]
	t_tree *tree; // Árbol de datos [cat, priority]-> [ls -l, priority]-> [grep,
	t_node *node; // Nodo de datos [cat]-> [ls -l]-> [grep]-> [>] -> [txt.txt]
	t_ref **ref;  // Referencia a datos [env, path]
	char			**av;
	int				ac;
}					t_memory;

# define PROMPT "minishell$ "

#endif