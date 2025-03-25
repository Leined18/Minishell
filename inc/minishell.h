/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:21:28 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/25 14:36:30 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
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
	pid_t			ppid;
	int				ignore[4];
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
void				clean_data(void **data);

// utils.c
void				ft_add_line_history(const char *line, char *file_path);
void				ft_load_history(char *path_history);
//int					ft_init_subshell(t_env *env, int *status);
int					process_input(t_data *data);

// shell.c
int					shell_loop(t_data *data);

// init.c
t_hash_table		*init_memory(char **envp, int size);

// signals_utils.c
void				ft_set_ignore(int *sigs, int n_sigs);
void				ft_set_default(int *sigs, int n_sigs);
void				handle_signal(int sig);
void				handle_sigint_adv_readine(int sig);

#endif