/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:29:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/06 10:31:25 by mvidal-h         ###   ########.fr       */
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
	return (1);
}

static int	ft_loop(t_env *env)
{
	int fd;
	
	if (!env)
		return (0);
	fd = 0;
	while (TRUE)
	{
		env->prompt = generate_prompt(env->mt_env);
		ft_putstr_fd("\033[2K\r", 1);
		env->input = readline(env->prompt);
		if (env->input == NULL)
			return (free_null((void **)&env->prompt), rl_clear_history(), 0);
		if (*env->input)
		{
			env->input = ft_straddc(env->input, '\n');
			fd = open(HISTORY, O_WRONLY | O_CREAT | O_APPEND, 0644);
			write(fd, env->input, ft_strlen(env->input));
			close(fd);
			add_history(env->input);
			process_input(env);
		}
		(free_null((void **)&env->prompt), free_null((void **)&env->input));
	}
	return (1);
}

void	ft_load_history(void)
{
	int		fd;
	char	*history_line;

	fd = open(HISTORY, O_RDONLY);
	while (1)
	{
		history_line = get_next_line(fd);
		if (!history_line)
			break ;
		add_history(history_line);
		free(history_line);
	}
	close(fd);
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
		ft_load_history();
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
