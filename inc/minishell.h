/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:21:28 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/26 14:30:08 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "config.h"
# include "exe.h"
# include "libft.h"
# include "mt.h"
# include "parse.h"

typedef struct s_data
{
	pid_t			pid;
	char			**av;
	int				ac;
	char			**envp;
}					t_data;

typedef struct s_memory
{
	t_data          *data;
	t_hash_table	*ht;
}					t_memory;

# define PROMPT "minishell$ "

#endif