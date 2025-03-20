/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:29:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/20 15:05:50 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_sig_received;

void	set_sigint_last_status(t_env *env)
{
	env->last_status = 130;
	g_sig_received = 0;
}

void	manage_input(char *aux_input, t_data *data)
{
	t_env	*env;

	env = data->envp;
	env->input = ft_expand_input(aux_input, env);
	ft_add_line_history(aux_input, env->path_history);
	process_input(data);
}

int	shell_loop(t_data *data)
{
	char	*aux_input;
	t_env	*env;

	env = data->envp;
	if (!env)
		return (0);
	g_sig_received = 0;
	while (TRUE)
	{
		signal(SIGINT, handle_signal);
		env->prompt = generate_prompt(env->mt_env);
		aux_input = readline(env->prompt);
		if (g_sig_received == SIGINT)
			set_sigint_last_status(env);
		if (aux_input == NULL)
		{
			ft_printf("exit\n");
			return (free_null((void **)&env->prompt), rl_clear_history(), 0);
		}
		if (*aux_input)
			manage_input(aux_input, data);
		(free_null((void **)&env->prompt), free_null((void **)&aux_input),
			free_null((void **)&env->input));
	}
	return (1);
}

// cat | sort | < entrada.txt > salida.txt
// cat | sort | uniq < entrada.txt > salida.txt
// cat | sort < entrada1.txt | uniq < entrada2.txt > salida.txt
