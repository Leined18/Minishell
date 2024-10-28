/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:29:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/28 15:38:15 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "commands.h"

void	shell_loop(char **envp, pid_t pid)
{
	char		*input;
	static char	**env = NULL;

	if (!env)
		env = envp;
	while (1) // Loop para esperar nueva entrada
	{
		ft_printf(PROMPT);
		input = get_next_line(0);
		if (!input)
		{
			ft_printf("exit\n");
			break ;
		}
		process_input(input, env);
		free_null(input);
		ft_successful("Shell loop ended", 0);
		send_signal(pid, SIGUSR1); // Manda señal al padre
		pause();                   // Espera señal del padre para continuar
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
	}
	else
		ft_error("Failed to parse command", 1);
}