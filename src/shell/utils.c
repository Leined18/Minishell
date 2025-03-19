/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:19:30 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/19 17:06:35 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_input(t_data *data)
{
	t_mt	*parsed_tree;
	t_env 	*env;

	env = data->envp;
	if (!env->input || !*env->input)
		return (0);
	parsed_tree = ft_parse_input(env->input);
	if (!parsed_tree)
		return (env->last_status = 2, 0);
	if (ft_mtsearch_key(parsed_tree, "./minishell"))
		signal(SIGINT, SIG_IGN);
	ft_execute_tree(parsed_tree, env, 0);
	restore_stdin_stdout(env);
	if (env->error_infile_name)
	{
		print_openfile_error(env->error_infile_name);
		free_null((void **)&env->error_infile_name);
	}
	ft_mtclear(&parsed_tree);
	return (1);
}

void	ft_add_line_history(const char *line, char *file_path)
{
	int		fd;
	char	*copy;

	if (!line || !file_path)
		return ;
	fd = 0;
	add_history(line);
	fd = open(file_path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		return ;
	copy = ft_strtrim(line, " \v\t\n\r");
	if (!copy)
		return ;
	write(fd, copy, ft_strlen(copy));
	write(fd, "\n", 1);
	free(copy);
	close(fd);
}

void	ft_load_history(char *path_history)
{
	int		fd;
	char	*history_line;

	if (!path_history)
		return ;
	fd = open(path_history, O_RDONLY, 0644);
	if (fd < 0)
		return ;
	while (1)
	{
		history_line = get_next_line(fd);
		if (!history_line)
			break ;
		history_line[ft_strlen(history_line) - 1] = 0;
		add_history(history_line);
		free(history_line);
	}
	close(fd);
}

// int	ft_init_subshell(t_env *env, int *status)
// {
// 	int	pid;

// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		ft_load_history(env->path_history);
// 		signal(SIGINT, SIG_DFL);
// 		if (!ft_loop(env))
// 			exit(0);
// 	}
// 	if (pid < 0)
// 		return (ft_error("err", 0), 0);
// 	waitpid(pid, status, 0);
// 	return (*status);
// }
