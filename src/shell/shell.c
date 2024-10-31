/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:29:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/31 09:39:52 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
#include "minishell.h"
#include "shell.h"

void	shell_loop(char **envp, pid_t pid)
{
	char		*input;
	static char	**env = NULL;

	if (!env)
		env = envp;
	while (1)
	{
		ft_printf(PROMPT);
		input = get_next_line(0);
		if (!input)
			continue ;
		process_input(input, env);
		free_null((void *)&input);
		send_signal(pid, SIGUSR1);
		pause();
	}
}

void	process_input(char *input, char **envp)
{
	t_command *cmd;

	if (!input || !*input)
		return ;
	input[strcspn(input, "\n")] = 0;
	cmd = parse_command(input, envp);
	if (cmd)
	{
		execute_command(cmd);
		free_command(&cmd);
	}
	else
		ft_error("Failed to parse command\n", 1);
}
