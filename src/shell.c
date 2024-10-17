/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:29:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/17 12:25:26 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_loop(char **envp)
{
	char	*input;

	while (1)
	{
		write(1, "minishell> ", 11);
		input = get_next_line(0);
		if (!input)
		{
			write(1, "exit\n", 5);
			break ;
		}
		process_input(input, envp);
		free(input);
	}
}

void	process_input(char *input, char **envp)
{
	t_command *cmd;

	input[strcspn(input, "\n")] = 0;
	cmd = parse_command(input, envp);
	if (cmd)
	{
		execute_command(cmd);
		free_command(cmd);
		send_signal(getppid(), SIGUSR1);
	}
	else
		ft_error("Failed to parse command", 1);
}