/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:29:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/09 11:02:10 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_input(char *input, t_data *data)
{
	t_command	*cmd;

	if (!input || !*input)
		return (0);
	input[strcspn(input, "\n")] = 0;
	cmd = parse_command(input, NULL, &data->list);
	if (cmd)
	{
		data->pid = fork();
		if (data->pid < 0)
			return (ft_error("Failed to fork\n", 0), 0);
		if (data->pid == 0)
		{
			execute_command(cmd);
		}
		free_command(&cmd);
	}
	else
		return (ft_error("Failed to parse command\n", 0), 0);
	return (1);
}

int	shell_loop(t_memory *mem)
{
	char	*input;

	while (1)
	{
		// Muestra el prompt y espera la entrada del usuario
		input = readline(PROMPT);
		// Si no puede leer, liberamos historial y salimos con 0(error)
		if (!input)
			return (rl_clear_history(), 0);
		// Si la entrada es "exit" salimos con 1 (correcto)
		if (ft_strlen(input) == 4 && ft_strncmp(input, "exit", 4) == 0)
			return (free_null((void **)&input), rl_clear_history(), 1);
		// Si el usuario escribió algo, se agrega al historial y se procesa.
		if (*input)
		{
			add_history(input);
			//$DIVIDIR ENTRADA EN COMANDOS (PARSEAR Y DEMAS)
			process_input(input, mem->data);
			//$se encargará de hacer el bucle en todos los comandos (desde solo 1 a n)
		}
		// liberamos input para leer uno nuevo y que no se quede sin liberar.
		free_null((void **)&input);
		pause();
	}
}
