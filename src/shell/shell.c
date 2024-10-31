/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:29:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/31 11:01:14 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
#include "minishell.h"
#include "shell.h"

int	shell_loop(char **envp, pid_t pid)
{
	char		*input;
	static char	**env = NULL;

	if (!env)
		env = envp;
	while (1)
	{
		ft_printf(PROMPT);
		input = get_next_line(1);
		if (!input)
			continue ;
		if (!process_input(input, env, pid))
			return (free_null((void *)&input), 0);
		free_null((void *)&input);
		pause();
	}
}

int	process_input(char *input, char **envp, pid_t pid)
{
	t_command	*cmd;

	if (!input || !*input)
		return (0);
	input[strcspn(input, "\n")] = 0;
	cmd = parse_command(input, envp);
	if (cmd)
	{
		pid = fork();
		if (pid < 0)
			return (ft_error("Failed to fork\n", 0), 0);
		if (pid == 0)
			execute_command(cmd);
		free_command(&cmd);
	}
	else
		return (ft_error("Failed to parse command\n", 0), 0);
	return (1);
}
