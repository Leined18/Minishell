/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:29:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/03 17:59:00 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_input(t_env *env)
{
	t_mt	*parsed_tree;

	if (!env->input || !*env->input)
		return (0);
	parsed_tree = ft_parse_input(env->input);
	if (!parsed_tree)
		return (env->last_status = 2, 0);
	ft_execute_tree(parsed_tree, env, 0);
	restore_stdin_stdout(env);
	ft_mtclear(&parsed_tree);
	(void)env->last_status;
	return (1);
}

static int	ft_loop(t_env *env)
{
	if (!env)
		return (0);
	while (TRUE)
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
	return (1);
}

int	shell_loop(t_hash_table *mem)
{
	t_env				*env;
	int					status;
	struct sigaction	sa;
	int					pid;

	env = (t_env *)mem->methods.search_data(mem, "envp");
	pid = fork();
	if (pid == 0)
	{
		sa.sa_sigaction = handle_signal;
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGINT, &sa, NULL);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGCHLD, &sa, NULL);
		if (!ft_loop(env))
			exit(0);
	}
	if (pid < 0)
		return (ft_error("err", 0), 0);
	waitpid(pid, &status, 0);
	return (status);
}
// cat | sort | < entrada.txt > salida.txt
// cat | sort | uniq < entrada.txt > salida.txt
// cat | sort < entrada1.txt | uniq < entrada2.txt > salida.txt
