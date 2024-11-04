/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:29:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/04 11:20:58 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
#include "minishell.h"
#include "shell.h"

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

int	shell_loop(char **envp, pid_t pid)
{
	char		*input;
	static char	**env = NULL;

	if (!env)
		env = envp;
	while (1)
	{
		// Muestra el prompt y espera la entrada del usuario
		input = readline(PROMPT);
		//Si no puede leer, liberamos historial y salimos con 0(error)
		if (!input)
			return (rl_clear_history(), 0);
		// Si la entrada es "exit" salimos con 1 (correcto)
		if (ft_strlen(input) == 4 && ft_strncmp(input, "exit", 4) == 0)
			return (free_null((void *)&input), rl_clear_history(), 1);
		// Si el usuario escribió algo, se agrega al historial y se procesa.
		if (*input)
		{
			add_history(input);
			process_input(input, env, pid);
		}
		//liberamos input para leer uno nuevo y que no se quede sin liberar.
		free_null((void *)&input);
	}
}
