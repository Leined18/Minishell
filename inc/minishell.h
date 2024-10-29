/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:21:28 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/29 11:24:56 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "config.h"
# include "libft.h"

typedef struct s_data
{
	t_command		*command;
    pid_t           pid;
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

#endif