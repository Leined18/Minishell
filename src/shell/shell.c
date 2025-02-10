/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:29:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/02/10 11:34:21 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_input(t_env *env)
{
	t_mt	*parsed_lst;

	if (!env->input || !*env->input)
		return (0);
	parsed_lst = ft_parse_input(env->input);
	ft_execute_tree(parsed_lst, env, 0);
	/* ft_execute_tree(parsed_lst, NULL, env, ft_execute_node); */
	ft_mtclear(&parsed_lst);
	return (1);
}

void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");           // Nueva línea para manejar Ctrl+C
		rl_on_new_line();       // Indicar que se comienza una nueva línea
		rl_replace_line("", 0); // Reemplazar la línea actual (vaciarla)
		rl_redisplay();         // Redistribuir el prompt
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

	signal(SIGINT, handle_signal);  // Maneja Ctrl+C
	signal(SIGUSR1, handle_signal); // Maneja
	signal(SIGQUIT, SIG_IGN);       // Ignora Ctrl+'\'
	signal(SIGTSTP, SIG_IGN);       // Ignora Ctrl+Z
	env = (t_env *)mem->methods.search_data(mem, "envp");
	while (1)
	{
		env->prompt = generate_prompt(env->mt_env);
		env->input = readline(env->prompt);
		if (env->input == NULL)
			return (free_null((void **)&env->prompt), rl_clear_history(), 0);
		if (*env->input)
		{
			add_history(env->input);
			process_input(env);
		}
		(free_null((void **)&env->prompt), free_null((void **)&env->input));
	}
	return (0);
}
