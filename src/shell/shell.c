/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:29:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/02/06 17:59:55 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_child_signal(int sig)
{
	if (sig == SIGINT) // control + c
	{
		ft_printf("\n");
		kill(getpid(), SIGKILL);
	}
	else if (sig == SIGUSR1)
	{
		printf("\n");     // Nueva línea
		rl_on_new_line(); // Indicar que estamos en una nueva línea
		rl_redisplay();   // Redistribuir el prompt
	}
}

int	process_input(t_env *env)
{
	t_mt	*parsed_tree;

	if (!env->input || !*env->input)
		return (0);
	signal(SIGINT, handle_child_signal);
	parsed_tree = ft_parse_input(env->input);
	execute_tree(parsed_tree, env, 0);
	restore_stdin_stdout(env);
	ft_mtclear(&parsed_tree);
	return (1);
}

void	handle_signal(int sig)
{
	if (sig == SIGINT) // control + c
	{
		//printf("\n");           // Nueva línea para manejar Ctrl+C
		//rl_on_new_line();       // Indicar que se comienza una nueva línea
		//rl_replace_line("", 0); // Reemplazar la línea actual (vaciarla)
		//rl_redisplay();         // Redistribuir el prompt
	}
	else if (sig == SIGUSR1)
	{
		printf("\n");     // Nueva línea
		rl_on_new_line(); // Indicar que estamos en una nueva línea
		rl_redisplay();   // Redistribuir el prompt
	}
}

int	shell_loop(t_hash_table *mem)
{
	t_env	*env;

	signal(SIGINT, SIG_IGN);  // Maneja Ctrl+C
	signal(SIGUSR1, handle_signal); // Maneja
	signal(SIGQUIT, SIG_IGN);       // Ignora Ctrl+'\'
	signal(SIGTSTP, SIG_IGN);       // Ignora Ctrl+Z
	env = (t_env *)mem->methods.search_data(mem, "envp");
	while (1)
	{
		env->prompt = generate_prompt(env->mt_env);
		env->input = readline(env->prompt);
		if (env->input == NULL)
			return (free(env->prompt), rl_clear_history(), 0);
		if (*env->input)
		{
			add_history(env->input);
			process_input(env);
		}
		(free(env->prompt), free_null((void **)&env->input));
	}
	return (0);
}
