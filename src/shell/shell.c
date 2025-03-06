/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:29:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/06 10:58:28 by danpalac         ###   ########.fr       */
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

static void	ft_add_line_history(const char *line)
{
	int		fd;
	char	*copy;

	if (!line)
		return ;
	fd = 0;
	copy = ft_strtrim(line, " \v\t\n\r");
	if (!copy)
		return ;
	add_history(copy);
	fd = open(HISTORY, O_WRONLY | O_CREAT | O_APPEND, 0644);
	write(fd, copy, ft_strlen(copy));
	write(fd, "\n", 1);
	free(copy);
	close(fd);
}

static int	ft_loop(t_env *env)
{
	if (!env)
		return (0);
	while (TRUE)
	{
		env->prompt = generate_prompt(env->mt_env);
		ft_putstr_fd("\033[2K\r", 1);
		env->input = readline(env->prompt);
		if (env->input == NULL)
			return (free_null((void **)&env->prompt), rl_clear_history(), 0);
		if (*env->input)
		{
			ft_add_line_history(env->input);
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

int	ft_init_subshell(t_env *env, int *status)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		ft_load_history();
		if (!ft_loop(env))
			exit(0);
	}
	if (pid < 0)
		return (ft_error("err", 0), 0);
	waitpid(pid, status, 0);
	*status = update_last_status(*status);
	env->last_status = *status;
	return (*status);
}

int	shell_loop(t_hash_table *mem)
{
	t_env	*env;
	int		status;

	env = (t_env *)mem->methods.search_data(mem, "envp");
	while (ft_init_subshell(env, &status))
	{
		if (status < 128)
			break ;
		printf("\n");           // Nueva línea para manejar Ctrl+C
		rl_on_new_line();       // Indicar que se comienza una nueva línea
		rl_replace_line("", 0); // Reemplazar la línea actual (vaciarla)
		rl_redisplay();
	}
	return (status);
}
// cat | sort | < entrada.txt > salida.txt
// cat | sort | uniq < entrada.txt > salida.txt
// cat | sort < entrada1.txt | uniq < entrada2.txt > salida.txt
