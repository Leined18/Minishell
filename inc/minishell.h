/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:21:28 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/17 12:56:35 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <signal.h>

# define PROMPT "minishell$ "

void		signal_setup(void);
void		send_signal(int pid, int signal);
void		signal_handler(int signum);


void		shell_loop(char **envp, pid_t pid);
void		process_input(char *input, char **envp);
void		free_command(t_command *cmd);

#endif