/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:29:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/19 16:56:08 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	sig_received;

void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		sig_received = SIGINT;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	shell_loop(t_data *data)
{
	char	*aux_input;
	t_env	*env;

	env = data->envp;
	if (!env)
		return (0);
	sig_received = 0;
	while (TRUE)
	{
		signal(SIGINT, handle_signal);
		env->prompt = generate_prompt(env->mt_env);
		aux_input = readline(env->prompt);
		if (sig_received == SIGINT)
		{
			env->last_status = 130;
			sig_received = 0;
		}
		if (aux_input == NULL)
			return (free_null((void **)&env->prompt), rl_clear_history(), 0);
		if (*aux_input)
		{
			env->input = ft_expand_input(aux_input, env);
			ft_add_line_history(aux_input, env->path_history);
			free_null((void **)&aux_input);
			process_input(data);
			ft_set_ignore(data->ignore, 3);
		}
		(free_null((void **)&env->prompt), free_null((void **)&aux_input),
			free_null((void **)&env->input));
	}
	return (1);
}

// cat | sort | < entrada.txt > salida.txt
// cat | sort | uniq < entrada.txt > salida.txt
// cat | sort < entrada1.txt | uniq < entrada2.txt > salida.txt
